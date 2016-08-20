#ifndef __UI_H__
#define __UI_H__

#include <ncurses.h>

typedef struct post_window post_window;
struct post_window {
	WINDOW *w;
	int pos_y;
	int pos_x;
	post *post;
	
	post_window *head;
	post_window *tail;
}; 

void init_ui();
void close_ui();
post_window* create_windows(post* mypost);
void begin_window_selection(post_window *window);
void update_window(post_window *window);

#endif
