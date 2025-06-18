// *This was built off of the work of Sadek Baroudi(see below), all rights and credits to them.
/* Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>
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
#include "Orion.h"

#ifdef RGB_MATRIX_ENABLE

// Layout
//
//┌────────────────────────┐          ┌────────────────────────┐
//│ 05  04  03  02  01  00 │          │ 28  29  30  31  32  33 │
//│────────────────────────┤          ├────────────────────────│
//│ 06  07  08  09  10  11 │          │ 39  38  37  36  35  34 │
//│────────────────────────┤          ├────────────────────────│
//│ 17  16  15  14  13  12 │          │ 40  41  42  43  44  45 │
//├────────────────────────┤          ├────────────────────────┤
//│ 18  19  20  21  22  23 │          │ 51  50  49  48  47  46 │
//└───────────┬────────────┴───┐ ┌────┴────────────┬───────────┘
//            │ 27  26  25  24 │ │  52  53  54  55 │
//            └────────────────┘ └─────────────────┘
//
//

// use this matrix if you use the 6 column layout ----------------------------------------------

led_config_t g_led_config = { {
//COL   00     01      02       03      04      05      06        ROW 
    {   5,      4,      3,       2,      1,      0,     24    },//00
    {   6,      7,      8,       9,     10,     11,     25    },//01
    {  17,     16,     15,      14,     13,     12,     26    },//02
    {  18,     19,     20,      21,     22,     23,     27    },//03
    {  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },//04
    {  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },//05
    {  28,     29,     30,      31,     32,     33,     52    },//00
    {  39,     38,     37,      36,     35,     34,     53    },//01
    {  40,     41,     42,      43,     44,     45,     54    },//02
    {  51,     50,     49,      48,     47,     46,     55    },//03
    {  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },//04
    {  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },//05
}, {
    // Left
    {93 , 64}, // Thumb far
    {77 , 64}, // Thumb home
    {61 , 64}, // Thumb near
    {45 , 64}, // Thumb deep
    {77 , 64}, // C5 R4
    {81	, 38}, // C5 R3
    {85	, 25}, // C5 R2
    {89	, 12}, // C5 R1
    {74	, 6},  // C4 R1
    {70	, 20}, // C4 R2
    {66	, 33}, // C4 R3
    {62 , 64}, // C4 R4
    {48 , 64}, // C3 R4
    {52	, 26}, // C3 R3
    {56	, 12}, // C3 R2
    {60	, 0},  // C3 R1
    {43	, 0},  // C2 R1
    {39	, 12}, // C2 R2
    {35	, 26}, // C2 R3
    {13 , 64}, // C2 R4
    {17	, 31}, // C1 R3
    {21	, 18}, // C1 R2
    {25	, 4},  // C1 R1
    {7	, 5},  // C0 R1
    {3	, 19}, // C0 R2
    {0	, 32}, // C0 R3
    {0  , 64}, // C0 R4
    // Right
    {129, 64}, // Thumb far
    {145, 64}, // Thumb homing
    {161, 64}, // Thumb near
    {177, 64}, // Thumb deep
    {145, 51}, // C6 R4
    {141, 38}, // C6 R3 
    {137, 25}, // C6 R2 
    {133, 12}, // C6 R1 
    {148, 6},  // C7 R1 
    {152, 20}, // C7 R2 
    {156, 33}, // C7 R3
    {160, 46}, // C7 R4
    {174, 40}, // C8 R4
    {170, 26}, // C8 R3 
    {166, 12}, // C8 R2 
    {162, 0},  // C8 R1 
    {179, 0},  // C9 R1 
    {183, 12}, // C9 R2 
    {187, 26}, // C9 R3
    {191, 40}, // C9 R4
    {209, 45}, // C10 R4
    {205, 31}, // C10 R3 
    {201, 18}, // C10 R2 
    {197, 4},  // C10 R1 
    {211, 5},  // C11 R1 
    {216, 19}, // C11 R2 
    {220, 32}, // C11 R3
    {224, 46}, // C11 R4
}, {       
    //LEFT               
    1, 1,  1, 1,
    4, 4,  4, 4,
    4, 12, 4, 4,
    4, 12, 4, 4,
    4, 12, 4, 4,
    4, 12, 4, 4,
    1, 1,  1, 1,
    //RIGHT
    1, 1,  1, 1,
    4, 4,  4, 4,
    4, 12, 4, 4,
    4, 12, 4, 4,
    4, 12, 4, 4,
    4, 12, 4, 4,
    1, 1,  1, 1
} };

