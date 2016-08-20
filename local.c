#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>

#include "posts.h"
#include "parser.h"
#include "local.h"

//int main(int argc, char *argv[])
int local(const char *filename)
{
	FILE *fp;
	char *str;
	size_t sz;
	post *first_post;

	fp = fopen(filename, "r");
	if(fp == NULL) {
		fprintf(stderr, "File not found: %s\n", filename);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	sz = ftell(fp);
	str = malloc(sizeof(char) * (sz+1));
	rewind(fp);
	fread(str, sz, 1, fp);
	fclose(fp);
	str[sz+1] = '\0';
	
	if(sub_parse(str, &first_post) != 0) {
		fprintf(stderr, "Failed to parse json\n");
	}


	post *mypost = first_post;
	while (mypost->tail != NULL) {
		printf("%s\n", mypost->title);
		mypost = mypost->tail;
	}

	mypost = first_post;

	DEBUG("free memory");
	while (mypost != NULL) { 
		if(mypost->head != NULL)
			free(mypost->head);
		if(mypost->title != NULL)
			free(mypost->title);
		if(mypost->author != NULL)
			free(mypost->author);
		if(mypost->url != NULL)
			free(mypost->url);
		if(mypost->permalink != NULL)
			free(mypost->permalink);

		if(mypost->tail == NULL)
		{
			free(mypost);
			mypost = NULL;
		} else {
			mypost = mypost->tail;
		}
	} 
	
	free(str);

	return 0;
}
