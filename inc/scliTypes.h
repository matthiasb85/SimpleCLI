/*
 * scliTypes.h
 *
 *  Created on: 27.01.2016
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

#ifndef SCLI_TYPES_H_
#define SCLI_TYPES_H_

#include "SimpleCLI/cfg/scliConfig.h"
#include <stdint.h>

#define SCLI_CMD_LIST_END {0,"\0","\0",0}
#define SCLI_FIFO_EMPTY (-1)

#if SCLI_CMD_HIST < 256
typedef uint8_t SCLI_BUF_IDX;
#else
typedef uint16_t SCLI_BUF_IDX;
#endif

#if SCLI_CMD_MAX_LEN < 256
typedef uint8_t SCLI_LINE_IDX;
#else
typedef uint16_t SCLI_LINE_IDX;
#endif

#if SCLI_GETCH_BUF_SIZE < 256
typedef uint8_t SCLI_FIFO_IDX;
#else
typedef uint16_t SCLI_FIFO_IDX;
#endif

typedef int32_t SCLI_CMD_RET;
typedef SCLI_CMD_RET (*SCLI_CMD_CB)(uint8_t argc, char **argv);

typedef enum
{
  SCLI_BUF_INIT = 0,
  SCLI_BUF_READY,
  SCLI_BUF_ESC_CLI,
  SCLI_BUF_ESC_CMD,
  SCLI_BUF_PARSING,
  SCLI_BUF_EXEC
}SCLI_BUF_STATE;

typedef struct
{
  SCLI_CMD_CB     CmdCallback;
  char            CmdName[SCLI_CMD_NAME_MAX_LEN+1];
  char            HelpShort[SCLI_S_HELP_MAX_LEN];
  const char      *HelpLong;
}SCLI_CMD_T;

typedef struct
{
  SCLI_BUF_STATE  State;
  char            Line[SCLI_CMD_MAX_LEN];
  SCLI_BUF_IDX    HistRefs;
  SCLI_LINE_IDX   LineIdx;
}SCLI_CMD_INPUT_T;

typedef struct
{
  void        (*SubsystemInit)(void (*)(uint8_t ));
  void        (*PutCh)(char ch);
  void        (*UserLevelHandOver)(SCLI_CMD_INPUT_T *Input);
  uint32_t    (*CriticalEnter)(void);
  void        (*CriticalExit)(uint32_t reg);
  SCLI_CMD_T  *UserLevelCommands;

}SCLI_INTERFACE_T;

typedef struct
{
  char            Buffer[SCLI_GETCH_BUF_SIZE];
  SCLI_FIFO_IDX   Write;
  SCLI_FIFO_IDX   Read;
  SCLI_FIFO_IDX   Size;
}SCLI_FIFO_T;


#endif /* SCLI_TYPES_H_ */
