/* FILENAME: posts.h
 *
 * DESCRIPTION: Data structure for storing comments.
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
 * ------
 *  The JSON format for posts is:
 *
 *  title: 	"string"
 *  kind: 	"string"
 *  domain: 	"string"
 *  selftext:	"string"
 *  id:		"string"
 *  author:	"string"
 *  thumbnail:	"string"
 *  subreddit_id: "string"
 *  permalink:	"string"
 *  name:	"string"
 *  url:	"string"
 */

#ifndef __POSTS_H__
#define __POSTS_H__

typedef struct post post;
struct post {
	char *title;
	char *author;
	char *url;
	char *permalink;
	
	post *head;
	post *tail;
}; 

#endif
