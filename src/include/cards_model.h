/* file: cards_model.h */
/* author: Yassin Achengli <0619883460@uma.es> */
/* date: 24/04/2022 */
/* Description: cards structure */

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

#ifndef __CARDS_MODEL_H__
#define __CARDS_MODEL_H__
#include <string.h>
#include "dateformat.h"

typedef struct {
	char* card_name;
	char* card_content;
	unsigned int card_id;
	
} card_wrapper;

#endif
