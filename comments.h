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
