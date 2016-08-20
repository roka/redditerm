#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>

#include "posts.h"
#include "debug.h"
#include "comments.h"

/* Get string from json object */
int get_string_jobj(json_object *jobj, const char *str, char **dest_str);
/* Get strings from json array */
void parse_post_idx(post *p, json_object *jobj);
/* Parse subreddit */
int sub_parse(char *str, post **post_list);
/* Parse comments */
int comments_parse(char *comments_str, comment **comments_list);

#endif
