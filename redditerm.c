#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <argp.h>

#include "local.h"
#include "https.h"
#include "posts.h"
#include "parser.h"
#include "ui.h"
#include "comments.h"

const char *argp_program_version = "redditerm";
const char *argp_program_bug_address = "<no@bugs.lol>";
static char doc[] = "A reddit terminal based client.";
static char args_doc[] = "[FILENAME]...";
static struct argp_option options[] = { 
	{ "local", 'l', "INFILE", 0, "Parse local json subreddit file."},
	{ "localcomments", 'c', "INFILE", 0, "Parse local json comments file."},
	{ 0 } 
};

struct arguments {
	enum { LOCAL, LOCALCOMMENTS, HTTPS } mode;
	char *infile;
	char *url;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	struct arguments *arguments = state->input;
	switch (key) {
		case 'l':
		       	arguments->mode = LOCAL;
			arguments->infile = arg;
		       	break;
		case 'c':
			arguments->mode = LOCALCOMMENTS;
			arguments->infile = arg;
			break;
		case ARGP_KEY_ARG:
			arguments->url = arg;
		       	return 0;
		default: return ARGP_ERR_UNKNOWN;
	}   
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char *argv[])
{
	struct arguments arguments;
	char *json_data = NULL;
	post *first_post;
	comment *first_comment,*test;

	arguments.mode = HTTPS;

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	if(arguments.mode == LOCAL) {
		DEBUG("LOCAL MODE");
		local(arguments.infile, &json_data);
	} else if(arguments.mode == LOCALCOMMENTS) {
		DEBUG("LOCAL COMMENTS MODE");
		local(arguments.infile, &json_data);
		printf("comments_parse=%d\n",
			comments_parse(json_data, &first_comment));
		test=first_comment;
		while( (test=test->tail) != NULL) {
			DEBUG("%s head=%p\ttail=%p child=%p", test->body, test->head, test->tail, test->child);
		}

		/* Free up memory */
		free_comments_list(first_comment);

		exit(0);
	}
	else if(arguments.mode == HTTPS) {
		DEBUG("HTTPS MODE");
		http( arguments.url, &json_data );
	}
	else {
		exit(1);
	}

	/* Parse subreddit */
	if(sub_parse(json_data, &first_post) != 0) {
		fprintf(stderr, "Failed to parse json\n");
		exit(1);
	}

	init_ui();

	post_window* window = create_windows(first_post);

	begin_window_selection(window);

	post *mypost = first_post;

	/* Free up memeory */
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

	if(json_data != NULL)
		free(json_data);
	
	close_ui();

	return 0;
}

