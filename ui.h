/* FILENAME: ui.h
 *
 * DESCRIPTION: Functions related to the ncurses UI.
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
