/*
 * scliString.h
 *
 *  Created on: 31.01.2016
 *      Author: Matthias Beckert <beckert.matthias@googlemail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SCLISTRING_H_
#define SCLISTRING_H_

#include "SimpleCLI/cfg/scliConfig.h"
#include "SimpleCLI/inc/scliTypes.h"

#if SCLI_USE_OWN_STR_FUNC > 0
extern uint32_t scliString_strlen(char *);
extern int      scliString_strncmp(char *, char *, size_t);
extern void     scliString_Memset(void*, int8_t, size_t);

#define strlen  scliString_strlen
#define strncmp scliString_strncmp
#define memset  scliString_Memset
#else
#include <string.h>
#endif

#endif /* SCLISTRING_H_ */