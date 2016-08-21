/* FILENAME: comments.c
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

#include <stdlib.h>
#include "comments.h"

/* Free the data contained in one comment entry */
void free_comment(comment *c)
{
	if(c->id != NULL)
		free(c->id);
	if(c->parent_id != NULL)
		free(c->parent_id);
	if(c->author != NULL)
		free(c->author);
	if(c->body != NULL)
		free(c->body);
}

/* Free a comments linked list */
void free_comments_list(comment *c)
{
	comment *c_tmp;

	while(c != NULL)
	{
		if(c->child != NULL)
			free_comments_list(c->child);

		c_tmp = c;
		c = c->tail;

		if(c_tmp != NULL) {
			free_comment(c_tmp);
			free(c_tmp);
		}
	}
}
