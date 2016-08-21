/* FILENAME: https.c
 *
 * DESCRIPTION: Functions for reading input from HTTPS.
 *
 * Copyright (C) 2016 Robin Karlsson <s.r.karlsson@gmail.com>.
 * Copyright (C) 2016 Daniel Ohlsson <dohlsson89@gmail.com>.
 *
 * This file is part of redditerm 
 *
 * redditerm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * redditerm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with redditerm.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

#include "debug.h"

struct string {
	char *ptr;
	size_t len;
};

void init_string(struct string *s) {
	  s->len = 0;
	    s->ptr = malloc(s->len+1);
	      if (s->ptr == NULL) {
		          fprintf(stderr, "malloc() failed\n");
			      exit(EXIT_FAILURE);
			        }
	        s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
	  size_t new_len = s->len + size*nmemb;
	    s->ptr = realloc(s->ptr, new_len+1);
	      if (s->ptr == NULL) {
		          fprintf(stderr, "realloc() failed\n");
			      exit(EXIT_FAILURE);
			        }
	        memcpy(s->ptr+s->len, ptr, size*nmemb);
		  s->ptr[new_len] = '\0';
		    s->len = new_len;

		      return size*nmemb;
}

int http(char *url, char **dest_str)
{
  	CURL *curl;
	CURLcode res;

	struct string s;
	long http_code;
	size_t len;

	init_string(&s);

 	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64; rv:48.0) Gecko/20100101 Firefox/48.0");

#ifdef SKIP_PEER_VERIFICATION
    /*
     * If you want to connect to a site who isn't using a certificate that is
     * signed by one of the certs in the CA bundle you have, you can skip the
     * verification of the server's certificate. This makes the connection
     * A LOT LESS SECURE.
     *
     * If you have a CA cert for the server stored someplace else than in the
     * default bundle, then the CURLOPT_CAPATH option might come handy for
     * you.
     */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
    /*
     * If the site you're connecting to uses a different host name that what
     * they have mentioned in their server certificate's commonName (or
     * subjectAltName) fields, libcurl will refuse to connect. You can skip
     * this check, but this will make the connection less secure.
     */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
		curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);

		curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
		if(http_code == 503) {
			fprintf(stderr, "Reddit is busy: (error code: 503)\n");
			exit(1);
		} else {
			DEBUG("http_code=%lu", http_code);
		}

		len = strlen(s.ptr);
		*dest_str = malloc(sizeof(char) * len);
		strcpy(*dest_str, s.ptr);
		free(s.ptr);
	}

	curl_global_cleanup();

	return 0;
}
