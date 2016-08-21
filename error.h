/* FILENAME: error.h
 *
 * DESCRIPTION: Used to define error codes.
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

#ifndef __ERROR_H__
#define __ERROR_H__

/* Common errors 0-99 */
#define SUCCESS 0

/* JSON errors 100-199 */
#define JSON_OBJECT_WRONG_TYPE	100
#define JSON_OBJECT_NOT_FOUND	101
#define JSON_FAILED_TO_PARSE	102

#endif
