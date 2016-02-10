/*
 * scliConfig.h
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

#ifndef SCLI_CFG_H_
#define SCLI_CFG_H_

/*
 * Usage flags
 */
#define SCLI_USE_OWN_PRINTF   1
#define SCLI_USE_OWN_STR_FUNC 1

/*
 * Size configuration
 */
#define SCLI_CMD_HIST         10
#define SCLI_CMD_MAX_LEN      64
#define SCLI_CMD_MAX_ARGS     10
#define SCLI_GETCH_BUF_SIZE   20
#define SCLI_CMD_NAME_MAX_LEN 10
#define SCLI_S_HELP_MAX_LEN   32

#if SCLI_USE_OWN_PRINTF > 0
#error "Remove this line and add own printf header"
#endif

#endif /* SCLI_CFG_H_ */
