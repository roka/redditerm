#include <ncurses.h>
#include <stdlib.h>

#include "posts.h"
#include "ui.h"

void init_ui() {
	initscr();
	cbreak();
	noecho();
	refresh();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	init_pair(2, COLOR_YELLOW, COLOR_RED);
	curs_set(0);
}

void close_ui() {
	endwin();
}

post_window* create_windows(post* mypost)
{
	int y, x, i;
	getmaxyx(stdscr, y, x);

	int windows = y/4;

	post_window* first_window;
	post_window* window;
	post_window* window_prev;

	for (i = 0; i < windows && mypost != NULL; i++) {
		window = malloc(sizeof(post_window));
		window->pos_y = i*4;
		window->pos_x = 0;
		window->w = newwin(3, 80, window->pos_y, window->pos_x);
		window->post = mypost;

		wbkgd(window->w, COLOR_PAIR(1));
		update_window(window);

		if (i == 0) {
			first_window = window;
			window->head = NULL;
		} else {
			window->head = window_prev;
			window_prev->tail = window;
		}

		window_prev = window;
		mypost = mypost->tail;
	}
	window->tail = NULL;

	return first_window;
}

void begin_window_selection(post_window *window)
{
	char ch;
	wbkgd(window->w, COLOR_PAIR(2));
	update_window(window);

	while((ch = getch()) != 'q') {
		switch(ch) {
			case 'k':
				if (window->head != NULL) {
					wbkgd(window->head->w, COLOR_PAIR(2));
					update_window(window->head);

					wbkgd(window->w, COLOR_PAIR(1));
					update_window(window);

					window = window->head;
				}
				break;
			case 'j':
				if (window->tail != NULL) {
					wbkgd(window->tail->w, COLOR_PAIR(2));
					update_window(window->tail);

					wbkgd(window->w, COLOR_PAIR(1));
					update_window(window);

					window = window->tail;
				}
				break;
		}
	}
}

void update_window(post_window *window)
{
	wmove(window->w, 1, 1);
	wprintw(window->w, window->post->title);
	wrefresh(window->w);
}
