/* FILENAME: local.c
 *
 * DESCRIPTION: Function for reading JSON data from local files.
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
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>

#include "posts.h"
#include "parser.h"
#include "local.h"

int local(const char *filename, char **dest_str)
{
	FILE *fp;
	size_t sz;

	fp = fopen(filename, "r");
	if(fp == NULL) {
		fprintf(stderr, "File not found: %s\n", filename);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	sz = ftell(fp);
	*dest_str = malloc(sizeof(char) * (sz+1));
	rewind(fp);
	fread(*dest_str, sz, 1, fp);
	fclose(fp);
	(*dest_str)[sz+1] = '\0';

	return 0;
}
