/* Copyright 2017 Joseph Wasson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

typedef enum { STENO_MODE_BOLT, STENO_MODE_GEMINI } steno_mode_t;

bool     process_steno(uint16_t keycode, keyrecord_t *record);
// CUSTOMISATION BEGIN
#ifdef STENO_REPEAT
void     steno_task(void);
#endif
// CUSTOMISATION END
void     steno_init(void);
void     steno_set_mode(steno_mode_t mode);
uint8_t *steno_get_state(void);
uint8_t *steno_get_chord(void);
