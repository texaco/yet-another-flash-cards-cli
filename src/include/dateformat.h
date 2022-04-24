/* file: dateformat.h */
/* author: Yassin Achengli <0619883460@uma.es> */
/* date: 24/04/2022 */
/* Description: date format for cards view*/

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program; see the file COPYING.  If not, see */
/* <https://www.gnu.org/licenses/>. */


#ifndef __DATE_FORMAT_H__
#define __DATE_FORMAT_H__
typedef struct {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
}date_format;

char* date_printable (const date_format date);
#endif
