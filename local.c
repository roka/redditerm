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
