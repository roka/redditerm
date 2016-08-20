#include "local.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <argp.h>

void http(char *str)
{
	printf("http: %s\n", str);
}

const char *argp_program_version = "redditerm";
const char *argp_program_bug_address = "<no@bugs.lol>";
static char doc[] = "A reddit terminal based client.";
static char args_doc[] = "[FILENAME]...";
static struct argp_option options[] = { 
	{ "local", 'l', "INFILE", 0, "Parse local json file."},
	{ 0 } 
};

struct arguments {
	enum { LOCAL, HTTPS } mode;
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

	arguments.mode = HTTPS;

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	if(arguments.mode == LOCAL)
		local(arguments.infile);
	else if(arguments.mode == HTTPS)
		http( arguments.url );
	else
		exit(1);

	return 0;
}

