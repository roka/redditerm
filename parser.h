/* FILENAME: parser.h
 *
 * DESCRIPTION: Functions for parsing JSON data.
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
