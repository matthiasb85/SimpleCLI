/*
 * scliString.c
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

#include "SimpleCLI/inc/scliString.h"

#if SCLI_USE_OWN_STR_FUNC > 0

uint32_t scliString_strlen(char *str)
{
  uint32_t i = 0;

  while(str[i])
    i++;

  return i;
}

int scliString_strncmp(char * str1,char *str2,size_t Len)
{
  size_t i = 0;

  for(i=0; i < Len; i++)
  {
    if(str1[i] != str2[i])
      return -1;
  }

  return 0;
}
void scliString_memset(void* buf, int8_t Val,size_t Len)
{
  int8_t *target = (int8_t *)buf;
  size_t i = 0;

  for(i=0; i < Len; i++)
    target[i] = Val;

}
#endif
