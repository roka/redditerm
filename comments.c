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
