/* FILENAME: comments.h
 *
 * DESCRIPTION: Contains the data structure for the comments linked list 
 * and related functions.
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

#ifndef __COMMENTS_H__
#define __COMMENTS_H__

typedef struct comment comment;
struct comment {
	char *id;
	char *parent_id;
	int score;
	char *author;
	char *body;
	int depth;
	
	comment *head;
	comment *tail;
	comment *child;
}; 

/* Free the data contained in one comment entry */
void free_comment(comment *c);

/* Free a comments linked list */
void free_comments_list(comment *c); 

#endif
