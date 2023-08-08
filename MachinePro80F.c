/*******************************************************************************
 * Size: 40 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MACHINEPRO80F
#define MACHINEPRO80F 1
#endif

#if MACHINEPRO80F

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0041 "A" */
    0x3, 0xf0, 0x0, 0x21, 0x0, 0xe, 0xc, 0x0,
    0x83, 0x40, 0x39, 0xc3, 0x2, 0x7f, 0x10, 0xe7,
    0xf1, 0x89, 0xff, 0xe4, 0x9f, 0xce, 0x49, 0xfc,
    0xe6, 0x9f, 0x2, 0x79, 0xf0, 0x27, 0x9f, 0xfe,
    0x78, 0x0, 0x7, 0x80, 0x0, 0x79, 0xff, 0xe7,
    0x9f, 0xfe, 0x79, 0xff, 0xe7, 0x9f, 0xfe, 0x79,
    0xff, 0xe7, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c,
    0x2, 0x7f, 0xc0, 0x3f, 0x7c, 0x1, 0xf3, 0xc0,
    0x1f, 0x3c, 0x0, 0xf1, 0xc0, 0xf,

    /* U+0042 "B" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x0, 0xc2, 0x0,
    0x50, 0x9f, 0xe3, 0x27, 0xfe, 0x49, 0xff, 0x8a,
    0x7f, 0xe2, 0x9c, 0x8, 0xe7, 0x2, 0x39, 0xff,
    0x8e, 0x0, 0xf, 0x80, 0x4, 0xe7, 0xfe, 0x39,
    0xff, 0x8e, 0x7f, 0xe3, 0x9f, 0xf8, 0xe7, 0xfe,
    0x39, 0xc2, 0x4e, 0x7f, 0x8f, 0x80, 0x13, 0xe0,
    0x3, 0xf8, 0x0, 0xff, 0xff, 0xff, 0x7f, 0xff,
    0x1f, 0xff, 0xc3, 0xff, 0xc0, 0xff, 0xf0,

    /* U+0043 "C" */
    0xf, 0xfc, 0x2, 0x1, 0x3, 0x80, 0x60, 0x9f,
    0xe4, 0xe7, 0xf9, 0xa3, 0xfe, 0x68, 0xff, 0x9e,
    0x3f, 0xff, 0x8f, 0x7, 0xe3, 0xc1, 0xf8, 0xc0,
    0x3e, 0x30, 0xf, 0x8c, 0x0, 0x23, 0x0, 0x8,
    0xc0, 0x2, 0x30, 0x38, 0x8c, 0x9, 0x23, 0x2,
    0x49, 0x40, 0x99, 0x9f, 0xe6, 0x60, 0x1, 0xce,
    0x1, 0xf3, 0x80, 0x7c, 0x7f, 0xff, 0xf, 0xff,
    0xc1, 0xff, 0xf0, 0x3f, 0xf0, 0xf, 0xfc,

    /* U+0044 "D" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x0, 0xc2, 0x0,
    0x50, 0x9f, 0xe6, 0x27, 0xfe, 0x49, 0xff, 0x9a,
    0x7f, 0xe6, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0,
    0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79,
    0xc0, 0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7, 0xe,
    0x79, 0xc2, 0x1e, 0x7f, 0x9f, 0x80, 0x17, 0xe0,
    0x3, 0xf8, 0x0, 0xff, 0xff, 0xff, 0x7f, 0xff,
    0x1f, 0xff, 0xc3, 0xff, 0xc0, 0xff, 0xf0,

    /* U+0045 "E" */
    0xff, 0xfc, 0x80, 0x4, 0x80, 0x6, 0x9f, 0xfe,
    0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff,
    0x9c, 0x0, 0x9c, 0x0, 0x9f, 0xf0, 0x80, 0x10,
    0x80, 0x18, 0x9f, 0xf8, 0x9f, 0xfc, 0x9f, 0xfc,
    0x9f, 0xfc, 0x9f, 0xfc, 0x9c, 0x0, 0x9f, 0xfc,
    0x80, 0x4, 0x80, 0x6, 0x80, 0x6, 0xff, 0xfe,
    0x7f, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x3f, 0xff,

    /* U+0046 "F" */
    0xff, 0xfc, 0x80, 0x4, 0x80, 0x6, 0x9f, 0xfe,
    0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff,
    0x9c, 0x0, 0x9c, 0x0, 0x9f, 0xf0, 0x80, 0x10,
    0x80, 0x18, 0x9f, 0xf8, 0x9f, 0xfc, 0x9f, 0xfc,
    0x9f, 0xfc, 0x9f, 0xfc, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0xfc, 0x0,
    0x7c, 0x0, 0x7c, 0x0, 0x3c, 0x0, 0x3c, 0x0,

    /* U+0047 "G" */
    0xf, 0xfc, 0x2, 0x1, 0x3, 0x80, 0x30, 0x9f,
    0xe4, 0xe7, 0xf9, 0xa3, 0xfe, 0x68, 0xff, 0x9e,
    0x3f, 0xff, 0x8f, 0x7, 0xe3, 0xc1, 0xf8, 0xff,
    0xfe, 0x30, 0x7, 0x8c, 0x1, 0xa3, 0xfe, 0x68,
    0xdf, 0x9e, 0x37, 0xe7, 0x8c, 0xf9, 0xe3, 0x3e,
    0x79, 0x40, 0x9d, 0x9f, 0xe7, 0x60, 0x1, 0xce,
    0x0, 0x73, 0x80, 0x1c, 0x7f, 0xff, 0xf, 0xff,
    0xc1, 0xff, 0xf0, 0x3f, 0xfc, 0xf, 0xff,

    /* U+0048 "H" */
    0xf0, 0xf, 0x24, 0x2, 0x49, 0x80, 0x9a, 0x60,
    0x26, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0, 0x9e,
    0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xff,
    0x9e, 0x0, 0x7, 0x80, 0x1, 0xe7, 0xfe, 0x79,
    0xff, 0x9e, 0x7f, 0xe7, 0x9f, 0xf9, 0xe7, 0xfe,
    0x79, 0xc0, 0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7,
    0x2, 0x79, 0xc0, 0x9f, 0xf0, 0x3f, 0x7c, 0x7,
    0xdf, 0x1, 0xf3, 0xc0, 0x3c, 0xf0, 0xf,

    /* U+0049 "I" */
    0xf2, 0x49, 0xa6, 0x9e, 0x79, 0xe7, 0x9e, 0x79,
    0xe7, 0x9e, 0x79, 0xe7, 0x9e, 0x79, 0xe7, 0x9e,
    0x79, 0xff, 0x7d, 0xf3, 0xcf,

    /* U+004A "J" */
    0xff, 0xff, 0x20, 0x0, 0x48, 0x0, 0x1b, 0xff,
    0xe6, 0x7f, 0xf9, 0xcf, 0xfe, 0x73, 0xff, 0x9c,
    0x7f, 0xe7, 0x0, 0x9, 0xc0, 0x2, 0x70, 0x0,
    0x9c, 0x0, 0x27, 0x0, 0x9, 0xc0, 0x2, 0x70,
    0x0, 0x9f, 0xc0, 0x27, 0x90, 0x9, 0xe2, 0xe,
    0x78, 0x82, 0x5e, 0x3f, 0x8f, 0x90, 0x13, 0xd8,
    0x3, 0xf6, 0x0, 0xfc, 0xff, 0xff, 0x3f, 0xff,
    0x7, 0xff, 0xc0, 0xff, 0xc0, 0x1f, 0xf0,

    /* U+004B "K" */
    0xf0, 0xe, 0x22, 0x2, 0x48, 0x83, 0x92, 0x30,
    0x9e, 0x8c, 0xe7, 0xa3, 0x23, 0xf8, 0xf8, 0xfe,
    0x39, 0xff, 0x88, 0x7f, 0x22, 0x7f, 0xc8, 0x5f,
    0xc2, 0xf, 0xf0, 0x85, 0xf0, 0x22, 0x7c, 0x8,
    0x84, 0x2, 0x39, 0xc0, 0x8e, 0x90, 0x23, 0xe3,
    0x8, 0xf9, 0x42, 0x37, 0x98, 0x8c, 0xe1, 0x23,
    0x1e, 0x48, 0xc3, 0x9b, 0xf0, 0x7e, 0x7c, 0xf,
    0xcf, 0x3, 0xf3, 0xc0, 0x3c, 0x70, 0xf,

    /* U+004C "L" */
    0xf0, 0x0, 0x90, 0x0, 0x98, 0x0, 0x98, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9f, 0xfc,
    0x80, 0x4, 0x80, 0x6, 0x80, 0x6, 0xff, 0xfe,
    0x7f, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x3f, 0xff,

    /* U+004D "M" */
    0xf0, 0x0, 0x0, 0xe2, 0x20, 0x0, 0x2, 0x48,
    0xc0, 0x0, 0x39, 0x20, 0x80, 0x0, 0x86, 0x83,
    0x0, 0xe, 0x1a, 0x14, 0x0, 0x24, 0x78, 0x8c,
    0x3, 0x89, 0xe3, 0x90, 0x9, 0xe7, 0x8e, 0x30,
    0xe7, 0x9e, 0x3e, 0x42, 0x3e, 0x78, 0xf8, 0xb8,
    0xf9, 0xe3, 0xf9, 0xf, 0xe7, 0x8e, 0xea, 0x3f,
    0x9e, 0x38, 0xc7, 0xfe, 0x78, 0xe3, 0x1f, 0xc9,
    0xe3, 0x87, 0xff, 0x27, 0x8e, 0xf, 0xf0, 0x9e,
    0x38, 0x3f, 0xc2, 0x78, 0xe0, 0x7c, 0x9, 0xe3,
    0x80, 0xf0, 0x27, 0x8e, 0x0, 0x0, 0x9e, 0x38,
    0x0, 0x2, 0x78, 0xe0, 0x0, 0x9, 0xff, 0x80,
    0x0, 0x3f, 0x7e, 0x0, 0x0, 0x7c, 0xf8, 0x0,
    0x1, 0xf3, 0xe0, 0x0, 0x3, 0xc7, 0x80, 0x0,
    0xf,

    /* U+004E "N" */
    0xf0, 0x0, 0xe, 0x22, 0x0, 0x2, 0x48, 0xc0,
    0x0, 0x92, 0x8, 0x0, 0x26, 0x83, 0x0, 0x9,
    0xa1, 0x40, 0x2, 0x78, 0x8c, 0x0, 0x9e, 0x25,
    0x0, 0x27, 0x8e, 0x30, 0x9, 0xe3, 0x94, 0x2,
    0x78, 0xf8, 0xc0, 0x9e, 0x3f, 0x90, 0x27, 0x8f,
    0xe6, 0x9, 0xe3, 0x9c, 0x62, 0x78, 0xe3, 0x24,
    0x9e, 0x38, 0x71, 0xe7, 0x8e, 0xc, 0x89, 0xe3,
    0x83, 0xc2, 0x78, 0xe0, 0x33, 0x1e, 0x38, 0xf,
    0x7, 0x8e, 0x1, 0xc1, 0xe3, 0x80, 0x3e, 0x78,
    0xe0, 0x3, 0x9f, 0xf8, 0x0, 0xff, 0x7e, 0x0,
    0xf, 0xcf, 0x80, 0x1, 0xf3, 0xe0, 0x0, 0x3c,
    0x78, 0x0, 0xf,

    /* U+004F "O" */
    0xf, 0xfc, 0x0, 0x80, 0x40, 0x38, 0x6, 0x2,
    0x0, 0x10, 0xe7, 0xf9, 0x88, 0xff, 0xe4, 0x8f,
    0xfe, 0x68, 0xff, 0xe6, 0x8f, 0x2, 0x78, 0xf0,
    0x27, 0x8c, 0x2, 0x78, 0xc0, 0x27, 0x8c, 0x2,
    0x78, 0xc0, 0x27, 0x8c, 0x2, 0x78, 0xc0, 0x27,
    0x8c, 0x2, 0x78, 0xc0, 0xe7, 0x94, 0x8, 0x76,
    0x7f, 0x9f, 0x60, 0x1, 0xf3, 0x80, 0x7f, 0x38,
    0x7, 0xf1, 0xff, 0xff, 0xf, 0xff, 0xc0, 0x7f,
    0xfc, 0x3, 0xff, 0x0, 0x3f, 0xf0,

    /* U+0050 "P" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x1, 0x82, 0x0,
    0x10, 0x9f, 0xe6, 0x27, 0xfe, 0x49, 0xff, 0x9a,
    0x7f, 0xe6, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc3,
    0x9e, 0x70, 0x9f, 0x9f, 0xe7, 0xe0, 0x7, 0xf8,
    0x1, 0xfe, 0x7f, 0xff, 0x9f, 0xff, 0x27, 0xff,
    0xc9, 0xff, 0xc2, 0x7f, 0xf0, 0x9c, 0x0, 0x27,
    0x0, 0x9, 0xc0, 0x3, 0xf0, 0x0, 0x7c, 0x0,
    0x1f, 0x0, 0x3, 0xc0, 0x0, 0xf0, 0x0,

    /* U+0051 "Q" */
    0xf, 0xf0, 0x2, 0x4, 0x3, 0x80, 0xc0, 0x90,
    0x50, 0xe3, 0xe3, 0x23, 0xfe, 0x48, 0xff, 0x9a,
    0x3f, 0xe6, 0x8f, 0x89, 0xe3, 0xe2, 0x78, 0xe0,
    0x9e, 0x38, 0x27, 0x8e, 0x9, 0xe3, 0xf2, 0x78,
    0xe2, 0x9e, 0x38, 0xa7, 0x8e, 0x29, 0xe3, 0x8e,
    0x79, 0x22, 0x5f, 0x88, 0x8f, 0x64, 0x13, 0xde,
    0x3, 0xf3, 0x80, 0xfc, 0x78, 0xff, 0xe, 0x3f,
    0x1, 0xff, 0xc0, 0x3f, 0xc0, 0x7, 0xf0, 0x0,
    0xf0, 0x0, 0x1c, 0x0,

    /* U+0052 "R" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x0, 0xc2, 0x0,
    0x50, 0x9f, 0xe6, 0x27, 0xfe, 0x49, 0xff, 0x9a,
    0x7f, 0xe6, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc3,
    0x9e, 0x70, 0x9f, 0x9f, 0xe7, 0xe0, 0x3, 0xf8,
    0x0, 0xfe, 0x70, 0xff, 0x9c, 0x4f, 0x27, 0xe3,
    0xc9, 0xf9, 0x42, 0x7f, 0x98, 0x9c, 0xe9, 0x27,
    0x1e, 0x49, 0xc3, 0x9b, 0xf0, 0x7e, 0x7c, 0xf,
    0xdf, 0x1, 0xf3, 0xc0, 0x3c, 0xf0, 0xf,

    /* U+0053 "S" */
    0xf, 0xfc, 0x0, 0x80, 0x40, 0x38, 0x6, 0x2,
    0x0, 0x90, 0xe7, 0xf1, 0x89, 0xff, 0xc4, 0x9f,
    0xfc, 0x49, 0xff, 0xfe, 0x9f, 0x3, 0xf9, 0xf0,
    0x3f, 0x9f, 0xff, 0xf8, 0x0, 0x7, 0x80, 0x0,
    0x6f, 0xff, 0xc6, 0x7f, 0xfc, 0x73, 0xff, 0xc7,
    0xdf, 0xfc, 0x79, 0xff, 0xc7, 0x84, 0x12, 0x76,
    0x7f, 0x1f, 0x60, 0x9, 0xf3, 0x80, 0x7f, 0x38,
    0x7, 0xf1, 0xff, 0xff, 0xf, 0xff, 0xc0, 0xff,
    0xfc, 0x3, 0xff, 0x0, 0x3f, 0xf0,

    /* U+0054 "T" */
    0xff, 0xff, 0x20, 0x0, 0x48, 0x0, 0x1b, 0xf9,
    0xfe, 0x7e, 0x7f, 0xdf, 0x9f, 0xf3, 0xe7, 0xfc,
    0x79, 0xff, 0x2, 0x70, 0x0, 0x9c, 0x0, 0x27,
    0x0, 0x9, 0xc0, 0x2, 0x70, 0x0, 0x9c, 0x0,
    0x27, 0x0, 0x9, 0xc0, 0x2, 0x70, 0x0, 0x9c,
    0x0, 0x27, 0x0, 0x9, 0xc0, 0x2, 0x70, 0x0,
    0x9c, 0x0, 0x27, 0x0, 0xf, 0xc0, 0x1, 0xf0,
    0x0, 0x7c, 0x0, 0xf, 0x0, 0x3, 0xc0,

    /* U+0055 "U" */
    0xf0, 0x3, 0xc9, 0x0, 0x24, 0x98, 0x2, 0x69,
    0x80, 0x26, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c,
    0x2, 0x79, 0xc0, 0x27, 0x9c, 0x2, 0x79, 0xc0,
    0x27, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c, 0x2,
    0x79, 0xc0, 0x27, 0x9c, 0x2, 0x79, 0xc0, 0x27,
    0x9c, 0x2, 0x79, 0xc0, 0xe7, 0xa4, 0x9, 0x7c,
    0x7f, 0x8f, 0x48, 0x4, 0xf7, 0x0, 0x3f, 0x30,
    0x3, 0xf3, 0xff, 0xff, 0xf, 0xff, 0xc0, 0xff,
    0xfc, 0x3, 0xff, 0x0, 0x3f, 0xf0,

    /* U+0056 "V" */
    0xf0, 0xf, 0x24, 0x2, 0x49, 0x80, 0x9a, 0x60,
    0x26, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0, 0x9e,
    0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0,
    0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79,
    0xc0, 0x9e, 0x70, 0xe7, 0xa4, 0x25, 0xf1, 0xd9,
    0xf4, 0x89, 0x7d, 0xc2, 0x3f, 0x31, 0xf, 0xcf,
    0x9f, 0xf0, 0xe7, 0xf0, 0x3f, 0xfc, 0x3, 0xfc,
    0x0, 0xff, 0x0, 0xf, 0x0, 0x1, 0xc0,

    /* U+0057 "W" */
    0xf0, 0xe, 0x0, 0xe2, 0x40, 0x24, 0x2, 0x49,
    0x80, 0x98, 0x9, 0x26, 0x2, 0x60, 0x26, 0x9c,
    0x9, 0xc0, 0x9e, 0x70, 0x27, 0x2, 0x79, 0xc0,
    0x9c, 0x9, 0xe7, 0x2, 0x70, 0x27, 0x9c, 0x9,
    0xc0, 0x9e, 0x70, 0x27, 0x2, 0x79, 0xc0, 0x9c,
    0x9, 0xe7, 0x2, 0x70, 0x27, 0x9c, 0x9, 0xc0,
    0x9e, 0x70, 0x27, 0x2, 0x79, 0xc0, 0x9c, 0x9,
    0xe7, 0xe, 0x70, 0xe7, 0xa4, 0x22, 0x42, 0x9f,
    0x9d, 0x91, 0xb9, 0xf6, 0x88, 0x49, 0x17, 0xdc,
    0x27, 0xc4, 0x3f, 0x33, 0x1f, 0x28, 0xfc, 0xf1,
    0xff, 0x1f, 0xf0, 0xc7, 0xfc, 0x7f, 0x3, 0xff,
    0xff, 0xfc, 0x3, 0xfc, 0x3f, 0xc0, 0xf, 0xf0,
    0xff, 0x0, 0xf, 0x1, 0xf0, 0x0, 0x1c, 0x3,
    0xc0,

    /* U+0058 "X" */
    0xf0, 0x3, 0xc9, 0x0, 0x24, 0x98, 0x2, 0x69,
    0x80, 0x26, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c,
    0xe, 0x7e, 0x40, 0x9f, 0x66, 0x39, 0xf7, 0x94,
    0x7f, 0x39, 0xc7, 0xf3, 0xc1, 0xff, 0xa, 0x27,
    0xc3, 0x9c, 0x7c, 0x29, 0xc9, 0xe, 0x7f, 0x9c,
    0xa7, 0xfa, 0x49, 0xff, 0xe6, 0x9f, 0xce, 0x69,
    0xfc, 0xe7, 0x9f, 0x2, 0x79, 0xf0, 0x27, 0x9c,
    0x2, 0x7f, 0xc0, 0x3f, 0x7c, 0x1, 0xf3, 0xc0,
    0x1f, 0x3c, 0x0, 0xf1, 0xc0, 0xf,

    /* U+0059 "Y" */
    0xf0, 0xf, 0x24, 0x2, 0x49, 0x80, 0x9a, 0x60,
    0x26, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0, 0x9e,
    0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc3,
    0x9f, 0x10, 0x9f, 0x47, 0x67, 0xdc, 0x27, 0xf3,
    0x11, 0xfc, 0xf9, 0xff, 0xe, 0x7f, 0x3, 0x9f,
    0xc0, 0x27, 0xc0, 0x9, 0xf0, 0x2, 0x70, 0x0,
    0x9c, 0x0, 0x27, 0x0, 0xf, 0xc0, 0x1, 0xf0,
    0x0, 0x3c, 0x0, 0xf, 0x0, 0x1, 0xc0,

    /* U+005A "Z" */
    0xff, 0xff, 0xf2, 0x0, 0x0, 0x48, 0x0, 0x1,
    0xbf, 0xff, 0xc6, 0x7f, 0xfc, 0x9c, 0xff, 0xf2,
    0x73, 0xff, 0x27, 0xc7, 0xfc, 0x7f, 0x0, 0x29,
    0xfc, 0x0, 0x9f, 0xf0, 0xe, 0x7f, 0xc0, 0x27,
    0xfc, 0x3, 0x9f, 0xf0, 0x39, 0xff, 0x0, 0x87,
    0xf0, 0xe, 0x7f, 0xc0, 0x21, 0xfc, 0x3, 0x9f,
    0xf0, 0x9, 0x7f, 0x0, 0x23, 0xff, 0xfc, 0x80,
    0x0, 0x12, 0x0, 0x0, 0x68, 0x0, 0x1, 0xbf,
    0xff, 0xff, 0x7f, 0xff, 0xfc, 0xff, 0xff, 0xf3,
    0xff, 0xff, 0xc7, 0xff, 0xff,

    /* U+0061 "a" */
    0x3, 0xf0, 0x0, 0x21, 0x0, 0xe, 0xc, 0x0,
    0x83, 0x40, 0x39, 0xc3, 0x2, 0x7f, 0x10, 0xe7,
    0xf1, 0x89, 0xff, 0xe4, 0x9f, 0xce, 0x49, 0xfc,
    0xe6, 0x9f, 0x2, 0x79, 0xf0, 0x27, 0x9f, 0xfe,
    0x78, 0x0, 0x7, 0x80, 0x0, 0x79, 0xff, 0xe7,
    0x9f, 0xfe, 0x79, 0xff, 0xe7, 0x9f, 0xfe, 0x79,
    0xff, 0xe7, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c,
    0x2, 0x7f, 0xc0, 0x3f, 0x7c, 0x1, 0xf3, 0xc0,
    0x1f, 0x3c, 0x0, 0xf1, 0xc0, 0xf,

    /* U+0062 "b" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x0, 0xc2, 0x0,
    0x50, 0x9f, 0xe3, 0x27, 0xfe, 0x49, 0xff, 0x8a,
    0x7f, 0xe2, 0x9c, 0x8, 0xe7, 0x2, 0x39, 0xff,
    0x8e, 0x0, 0xf, 0x80, 0x4, 0xe7, 0xfe, 0x39,
    0xff, 0x8e, 0x7f, 0xe3, 0x9f, 0xf8, 0xe7, 0xfe,
    0x39, 0xc2, 0x4e, 0x7f, 0x8f, 0x80, 0x13, 0xe0,
    0x3, 0xf8, 0x0, 0xff, 0xff, 0xff, 0x7f, 0xff,
    0x1f, 0xff, 0xc3, 0xff, 0xc0, 0xff, 0xf0,

    /* U+0063 "c" */
    0xf, 0xfc, 0x2, 0x1, 0x3, 0x80, 0x60, 0x9f,
    0xe4, 0xe7, 0xf9, 0xa3, 0xfe, 0x68, 0xff, 0x9e,
    0x3f, 0xff, 0x8f, 0x7, 0xe3, 0xc1, 0xf8, 0xc0,
    0x3e, 0x30, 0xf, 0x8c, 0x0, 0x23, 0x0, 0x8,
    0xc0, 0x2, 0x30, 0x38, 0x8c, 0x9, 0x23, 0x2,
    0x49, 0x40, 0x99, 0x9f, 0xe6, 0x60, 0x1, 0xce,
    0x1, 0xf3, 0x80, 0x7c, 0x7f, 0xff, 0xf, 0xff,
    0xc1, 0xff, 0xf0, 0x3f, 0xf0, 0xf, 0xfc,

    /* U+0064 "d" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x0, 0xc2, 0x0,
    0x50, 0x9f, 0xe6, 0x27, 0xfe, 0x49, 0xff, 0x9a,
    0x7f, 0xe6, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0,
    0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79,
    0xc0, 0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7, 0xe,
    0x79, 0xc2, 0x1e, 0x7f, 0x9f, 0x80, 0x17, 0xe0,
    0x3, 0xf8, 0x0, 0xff, 0xff, 0xff, 0x7f, 0xff,
    0x1f, 0xff, 0xc3, 0xff, 0xc0, 0xff, 0xf0,

    /* U+0065 "e" */
    0xff, 0xfc, 0x80, 0x4, 0x80, 0x6, 0x9f, 0xfe,
    0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff,
    0x9c, 0x0, 0x9c, 0x0, 0x9f, 0xf0, 0x80, 0x10,
    0x80, 0x18, 0x9f, 0xf8, 0x9f, 0xfc, 0x9f, 0xfc,
    0x9f, 0xfc, 0x9f, 0xfc, 0x9c, 0x0, 0x9f, 0xfc,
    0x80, 0x4, 0x80, 0x6, 0x80, 0x6, 0xff, 0xfe,
    0x7f, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x3f, 0xff,

    /* U+0066 "f" */
    0xff, 0xfc, 0x80, 0x4, 0x80, 0x6, 0x9f, 0xfe,
    0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff, 0x9f, 0xff,
    0x9c, 0x0, 0x9c, 0x0, 0x9f, 0xf0, 0x80, 0x10,
    0x80, 0x18, 0x9f, 0xf8, 0x9f, 0xfc, 0x9f, 0xfc,
    0x9f, 0xfc, 0x9f, 0xfc, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0xfc, 0x0,
    0x7c, 0x0, 0x7c, 0x0, 0x3c, 0x0, 0x3c, 0x0,

    /* U+0067 "g" */
    0xf, 0xfc, 0x2, 0x1, 0x3, 0x80, 0x30, 0x9f,
    0xe4, 0xe7, 0xf9, 0xa3, 0xfe, 0x68, 0xff, 0x9e,
    0x3f, 0xff, 0x8f, 0x7, 0xe3, 0xc1, 0xf8, 0xff,
    0xfe, 0x30, 0x7, 0x8c, 0x1, 0xa3, 0xfe, 0x68,
    0xdf, 0x9e, 0x37, 0xe7, 0x8c, 0xf9, 0xe3, 0x3e,
    0x79, 0x40, 0x9d, 0x9f, 0xe7, 0x60, 0x1, 0xce,
    0x0, 0x73, 0x80, 0x1c, 0x7f, 0xff, 0xf, 0xff,
    0xc1, 0xff, 0xf0, 0x3f, 0xfc, 0xf, 0xff,

    /* U+0068 "h" */
    0xf0, 0xf, 0x24, 0x2, 0x49, 0x80, 0x9a, 0x60,
    0x26, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0, 0x9e,
    0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xff,
    0x9e, 0x0, 0x7, 0x80, 0x1, 0xe7, 0xfe, 0x79,
    0xff, 0x9e, 0x7f, 0xe7, 0x9f, 0xf9, 0xe7, 0xfe,
    0x79, 0xc0, 0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7,
    0x2, 0x79, 0xc0, 0x9f, 0xf0, 0x3f, 0x7c, 0x7,
    0xdf, 0x1, 0xf3, 0xc0, 0x3c, 0xf0, 0xf,

    /* U+0069 "i" */
    0xf2, 0x49, 0xa6, 0x9e, 0x79, 0xe7, 0x9e, 0x79,
    0xe7, 0x9e, 0x79, 0xe7, 0x9e, 0x79, 0xe7, 0x9e,
    0x79, 0xff, 0x7d, 0xf3, 0xcf,

    /* U+006A "j" */
    0xff, 0xff, 0x20, 0x0, 0x48, 0x0, 0x1b, 0xff,
    0xe6, 0x7f, 0xf9, 0xcf, 0xfe, 0x73, 0xff, 0x9c,
    0x7f, 0xe7, 0x0, 0x9, 0xc0, 0x2, 0x70, 0x0,
    0x9c, 0x0, 0x27, 0x0, 0x9, 0xc0, 0x2, 0x70,
    0x0, 0x9f, 0xc0, 0x27, 0x90, 0x9, 0xe2, 0xe,
    0x78, 0x82, 0x5e, 0x3f, 0x8f, 0x90, 0x13, 0xd8,
    0x3, 0xf6, 0x0, 0xfc, 0xff, 0xff, 0x3f, 0xff,
    0x7, 0xff, 0xc0, 0xff, 0xc0, 0x1f, 0xf0,

    /* U+006B "k" */
    0xf0, 0xe, 0x22, 0x2, 0x48, 0x83, 0x92, 0x30,
    0x9e, 0x8c, 0xe7, 0xa3, 0x23, 0xf8, 0xf8, 0xfe,
    0x39, 0xff, 0x88, 0x7f, 0x22, 0x7f, 0xc8, 0x5f,
    0xc2, 0xf, 0xf0, 0x85, 0xf0, 0x22, 0x7c, 0x8,
    0x84, 0x2, 0x39, 0xc0, 0x8e, 0x90, 0x23, 0xe3,
    0x8, 0xf9, 0x42, 0x37, 0x98, 0x8c, 0xe1, 0x23,
    0x1e, 0x48, 0xc3, 0x9b, 0xf0, 0x7e, 0x7c, 0xf,
    0xcf, 0x3, 0xf3, 0xc0, 0x3c, 0x70, 0xf,

    /* U+006C "l" */
    0xf0, 0x0, 0x90, 0x0, 0x98, 0x0, 0x98, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0,
    0x9c, 0x0, 0x9c, 0x0, 0x9c, 0x0, 0x9f, 0xfc,
    0x80, 0x4, 0x80, 0x6, 0x80, 0x6, 0xff, 0xfe,
    0x7f, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x3f, 0xff,

    /* U+006D "m" */
    0xf0, 0x0, 0x0, 0xe2, 0x20, 0x0, 0x2, 0x48,
    0xc0, 0x0, 0x39, 0x20, 0x80, 0x0, 0x86, 0x83,
    0x0, 0xe, 0x1a, 0x14, 0x0, 0x24, 0x78, 0x8c,
    0x3, 0x89, 0xe3, 0x90, 0x9, 0xe7, 0x8e, 0x30,
    0xe7, 0x9e, 0x3e, 0x42, 0x3e, 0x78, 0xf8, 0xb8,
    0xf9, 0xe3, 0xf9, 0xf, 0xe7, 0x8e, 0xea, 0x3f,
    0x9e, 0x38, 0xc7, 0xfe, 0x78, 0xe3, 0x1f, 0xc9,
    0xe3, 0x87, 0xff, 0x27, 0x8e, 0xf, 0xf0, 0x9e,
    0x38, 0x3f, 0xc2, 0x78, 0xe0, 0x7c, 0x9, 0xe3,
    0x80, 0xf0, 0x27, 0x8e, 0x0, 0x0, 0x9e, 0x38,
    0x0, 0x2, 0x78, 0xe0, 0x0, 0x9, 0xff, 0x80,
    0x0, 0x3f, 0x7e, 0x0, 0x0, 0x7c, 0xf8, 0x0,
    0x1, 0xf3, 0xe0, 0x0, 0x3, 0xc7, 0x80, 0x0,
    0xf,

    /* U+006E "n" */
    0xf0, 0x0, 0xe, 0x22, 0x0, 0x2, 0x48, 0xc0,
    0x0, 0x92, 0x8, 0x0, 0x26, 0x83, 0x0, 0x9,
    0xa1, 0x40, 0x2, 0x78, 0x8c, 0x0, 0x9e, 0x25,
    0x0, 0x27, 0x8e, 0x30, 0x9, 0xe3, 0x94, 0x2,
    0x78, 0xf8, 0xc0, 0x9e, 0x3f, 0x90, 0x27, 0x8f,
    0xe6, 0x9, 0xe3, 0x9c, 0x62, 0x78, 0xe3, 0x24,
    0x9e, 0x38, 0x71, 0xe7, 0x8e, 0xc, 0x89, 0xe3,
    0x83, 0xc2, 0x78, 0xe0, 0x33, 0x1e, 0x38, 0xf,
    0x7, 0x8e, 0x1, 0xc1, 0xe3, 0x80, 0x3e, 0x78,
    0xe0, 0x3, 0x9f, 0xf8, 0x0, 0xff, 0x7e, 0x0,
    0xf, 0xcf, 0x80, 0x1, 0xf3, 0xe0, 0x0, 0x3c,
    0x78, 0x0, 0xf,

    /* U+006F "o" */
    0xf, 0xfc, 0x0, 0x80, 0x40, 0x38, 0x6, 0x2,
    0x0, 0x10, 0xe7, 0xf9, 0x88, 0xff, 0xe4, 0x8f,
    0xfe, 0x68, 0xff, 0xe6, 0x8f, 0x2, 0x78, 0xf0,
    0x27, 0x8c, 0x2, 0x78, 0xc0, 0x27, 0x8c, 0x2,
    0x78, 0xc0, 0x27, 0x8c, 0x2, 0x78, 0xc0, 0x27,
    0x8c, 0x2, 0x78, 0xc0, 0xe7, 0x94, 0x8, 0x76,
    0x7f, 0x9f, 0x60, 0x1, 0xf3, 0x80, 0x7f, 0x38,
    0x7, 0xf1, 0xff, 0xff, 0xf, 0xff, 0xc0, 0x7f,
    0xfc, 0x3, 0xff, 0x0, 0x3f, 0xf0,

    /* U+0070 "p" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x1, 0x82, 0x0,
    0x10, 0x9f, 0xe6, 0x27, 0xfe, 0x49, 0xff, 0x9a,
    0x7f, 0xe6, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc3,
    0x9e, 0x70, 0x9f, 0x9f, 0xe7, 0xe0, 0x7, 0xf8,
    0x1, 0xfe, 0x7f, 0xff, 0x9f, 0xff, 0x27, 0xff,
    0xc9, 0xff, 0xc2, 0x7f, 0xf0, 0x9c, 0x0, 0x27,
    0x0, 0x9, 0xc0, 0x3, 0xf0, 0x0, 0x7c, 0x0,
    0x1f, 0x0, 0x3, 0xc0, 0x0, 0xf0, 0x0,

    /* U+0071 "q" */
    0xf, 0xf0, 0x2, 0x4, 0x3, 0x80, 0xc0, 0x90,
    0x50, 0xe3, 0xe3, 0x23, 0xfe, 0x48, 0xff, 0x9a,
    0x3f, 0xe6, 0x8f, 0x89, 0xe3, 0xe2, 0x78, 0xe0,
    0x9e, 0x38, 0x27, 0x8e, 0x9, 0xe3, 0xf2, 0x78,
    0xe2, 0x9e, 0x38, 0xa7, 0x8e, 0x29, 0xe3, 0x8e,
    0x79, 0x22, 0x5f, 0x88, 0x8f, 0x64, 0x13, 0xde,
    0x3, 0xf3, 0x80, 0xfc, 0x78, 0xff, 0xe, 0x3f,
    0x1, 0xff, 0xc0, 0x3f, 0xc0, 0x7, 0xf0, 0x0,
    0xf0, 0x0, 0x1c, 0x0,

    /* U+0072 "r" */
    0xff, 0xf0, 0x20, 0x4, 0x8, 0x0, 0xc2, 0x0,
    0x50, 0x9f, 0xe6, 0x27, 0xfe, 0x49, 0xff, 0x9a,
    0x7f, 0xe6, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc3,
    0x9e, 0x70, 0x9f, 0x9f, 0xe7, 0xe0, 0x3, 0xf8,
    0x0, 0xfe, 0x70, 0xff, 0x9c, 0x4f, 0x27, 0xe3,
    0xc9, 0xf9, 0x42, 0x7f, 0x98, 0x9c, 0xe9, 0x27,
    0x1e, 0x49, 0xc3, 0x9b, 0xf0, 0x7e, 0x7c, 0xf,
    0xdf, 0x1, 0xf3, 0xc0, 0x3c, 0xf0, 0xf,

    /* U+0073 "s" */
    0xf, 0xfc, 0x0, 0x80, 0x40, 0x38, 0x6, 0x2,
    0x0, 0x90, 0xe7, 0xf1, 0x89, 0xff, 0xc4, 0x9f,
    0xfc, 0x49, 0xff, 0xfe, 0x9f, 0x3, 0xf9, 0xf0,
    0x3f, 0x9f, 0xff, 0xf8, 0x0, 0x7, 0x80, 0x0,
    0x6f, 0xff, 0xc6, 0x7f, 0xfc, 0x73, 0xff, 0xc7,
    0xdf, 0xfc, 0x79, 0xff, 0xc7, 0x84, 0x12, 0x76,
    0x7f, 0x1f, 0x60, 0x9, 0xf3, 0x80, 0x7f, 0x38,
    0x7, 0xf1, 0xff, 0xff, 0xf, 0xff, 0xc0, 0xff,
    0xfc, 0x3, 0xff, 0x0, 0x3f, 0xf0,

    /* U+0074 "t" */
    0xff, 0xff, 0x20, 0x0, 0x48, 0x0, 0x1b, 0xf9,
    0xfe, 0x7e, 0x7f, 0xdf, 0x9f, 0xf3, 0xe7, 0xfc,
    0x79, 0xff, 0x2, 0x70, 0x0, 0x9c, 0x0, 0x27,
    0x0, 0x9, 0xc0, 0x2, 0x70, 0x0, 0x9c, 0x0,
    0x27, 0x0, 0x9, 0xc0, 0x2, 0x70, 0x0, 0x9c,
    0x0, 0x27, 0x0, 0x9, 0xc0, 0x2, 0x70, 0x0,
    0x9c, 0x0, 0x27, 0x0, 0xf, 0xc0, 0x1, 0xf0,
    0x0, 0x7c, 0x0, 0xf, 0x0, 0x3, 0xc0,

    /* U+0075 "u" */
    0xf0, 0x3, 0xc9, 0x0, 0x24, 0x98, 0x2, 0x69,
    0x80, 0x26, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c,
    0x2, 0x79, 0xc0, 0x27, 0x9c, 0x2, 0x79, 0xc0,
    0x27, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c, 0x2,
    0x79, 0xc0, 0x27, 0x9c, 0x2, 0x79, 0xc0, 0x27,
    0x9c, 0x2, 0x79, 0xc0, 0xe7, 0xa4, 0x9, 0x7c,
    0x7f, 0x8f, 0x48, 0x4, 0xf7, 0x0, 0x3f, 0x30,
    0x3, 0xf3, 0xff, 0xff, 0xf, 0xff, 0xc0, 0xff,
    0xfc, 0x3, 0xff, 0x0, 0x3f, 0xf0,

    /* U+0076 "v" */
    0xf0, 0xf, 0x24, 0x2, 0x49, 0x80, 0x9a, 0x60,
    0x26, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0, 0x9e,
    0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0,
    0x9e, 0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79,
    0xc0, 0x9e, 0x70, 0xe7, 0xa4, 0x25, 0xf1, 0xd9,
    0xf4, 0x89, 0x7d, 0xc2, 0x3f, 0x31, 0xf, 0xcf,
    0x9f, 0xf0, 0xe7, 0xf0, 0x3f, 0xfc, 0x3, 0xfc,
    0x0, 0xff, 0x0, 0xf, 0x0, 0x1, 0xc0,

    /* U+0077 "w" */
    0xf0, 0xe, 0x0, 0xe2, 0x40, 0x24, 0x2, 0x49,
    0x80, 0x98, 0x9, 0x26, 0x2, 0x60, 0x26, 0x9c,
    0x9, 0xc0, 0x9e, 0x70, 0x27, 0x2, 0x79, 0xc0,
    0x9c, 0x9, 0xe7, 0x2, 0x70, 0x27, 0x9c, 0x9,
    0xc0, 0x9e, 0x70, 0x27, 0x2, 0x79, 0xc0, 0x9c,
    0x9, 0xe7, 0x2, 0x70, 0x27, 0x9c, 0x9, 0xc0,
    0x9e, 0x70, 0x27, 0x2, 0x79, 0xc0, 0x9c, 0x9,
    0xe7, 0xe, 0x70, 0xe7, 0xa4, 0x22, 0x42, 0x9f,
    0x9d, 0x91, 0xb9, 0xf6, 0x88, 0x49, 0x17, 0xdc,
    0x27, 0xc4, 0x3f, 0x33, 0x1f, 0x28, 0xfc, 0xf1,
    0xff, 0x1f, 0xf0, 0xc7, 0xfc, 0x7f, 0x3, 0xff,
    0xff, 0xfc, 0x3, 0xfc, 0x3f, 0xc0, 0xf, 0xf0,
    0xff, 0x0, 0xf, 0x1, 0xf0, 0x0, 0x1c, 0x3,
    0xc0,

    /* U+0078 "x" */
    0xf0, 0x3, 0xc9, 0x0, 0x24, 0x98, 0x2, 0x69,
    0x80, 0x26, 0x9c, 0x2, 0x79, 0xc0, 0x27, 0x9c,
    0xe, 0x7e, 0x40, 0x9f, 0x66, 0x39, 0xf7, 0x94,
    0x7f, 0x39, 0xc7, 0xf3, 0xc1, 0xff, 0xa, 0x27,
    0xc3, 0x9c, 0x7c, 0x29, 0xc9, 0xe, 0x7f, 0x9c,
    0xa7, 0xfa, 0x49, 0xff, 0xe6, 0x9f, 0xce, 0x69,
    0xfc, 0xe7, 0x9f, 0x2, 0x79, 0xf0, 0x27, 0x9c,
    0x2, 0x7f, 0xc0, 0x3f, 0x7c, 0x1, 0xf3, 0xc0,
    0x1f, 0x3c, 0x0, 0xf1, 0xc0, 0xf,

    /* U+0079 "y" */
    0xf0, 0xf, 0x24, 0x2, 0x49, 0x80, 0x9a, 0x60,
    0x26, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc0, 0x9e,
    0x70, 0x27, 0x9c, 0x9, 0xe7, 0x2, 0x79, 0xc3,
    0x9f, 0x10, 0x9f, 0x47, 0x67, 0xdc, 0x27, 0xf3,
    0x11, 0xfc, 0xf9, 0xff, 0xe, 0x7f, 0x3, 0x9f,
    0xc0, 0x27, 0xc0, 0x9, 0xf0, 0x2, 0x70, 0x0,
    0x9c, 0x0, 0x27, 0x0, 0xf, 0xc0, 0x1, 0xf0,
    0x0, 0x3c, 0x0, 0xf, 0x0, 0x1, 0xc0,

    /* U+007A "z" */
    0xff, 0xff, 0xf2, 0x0, 0x0, 0x48, 0x0, 0x1,
    0xbf, 0xff, 0xc6, 0x7f, 0xfc, 0x9c, 0xff, 0xf2,
    0x73, 0xff, 0x27, 0xc7, 0xfc, 0x7f, 0x0, 0x29,
    0xfc, 0x0, 0x9f, 0xf0, 0xe, 0x7f, 0xc0, 0x27,
    0xfc, 0x3, 0x9f, 0xf0, 0x39, 0xff, 0x0, 0x87,
    0xf0, 0xe, 0x7f, 0xc0, 0x21, 0xfc, 0x3, 0x9f,
    0xf0, 0x9, 0x7f, 0x0, 0x23, 0xff, 0xfc, 0x80,
    0x0, 0x12, 0x0, 0x0, 0x68, 0x0, 0x1, 0xbf,
    0xff, 0xff, 0x7f, 0xff, 0xfc, 0xff, 0xff, 0xf3,
    0xff, 0xff, 0xc7, 0xff, 0xff
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 97, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 328, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 301, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 301, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 271, .box_w = 16, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 266, .box_w = 16, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 303, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 305, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 115, .box_w = 6, .box_h = 28, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 301, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 271, .box_w = 16, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 701, .adv_w = 490, .box_w = 30, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 806, .adv_w = 429, .box_w = 26, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 326, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 967, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 297, .box_w = 18, .box_h = 30, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1098, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1161, .adv_w = 326, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1231, .adv_w = 294, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1294, .adv_w = 332, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1364, .adv_w = 298, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1427, .adv_w = 486, .box_w = 30, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1532, .adv_w = 326, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1602, .adv_w = 298, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1665, .adv_w = 363, .box_w = 22, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1742, .adv_w = 328, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1812, .adv_w = 301, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1875, .adv_w = 301, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1938, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2001, .adv_w = 271, .box_w = 16, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2057, .adv_w = 266, .box_w = 16, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2113, .adv_w = 303, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2176, .adv_w = 305, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2239, .adv_w = 115, .box_w = 6, .box_h = 28, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2260, .adv_w = 301, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2323, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2386, .adv_w = 271, .box_w = 16, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2442, .adv_w = 490, .box_w = 30, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2547, .adv_w = 429, .box_w = 26, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2638, .adv_w = 326, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2708, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2771, .adv_w = 297, .box_w = 18, .box_h = 30, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2839, .adv_w = 300, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2902, .adv_w = 326, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2972, .adv_w = 294, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3035, .adv_w = 332, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3105, .adv_w = 298, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3168, .adv_w = 486, .box_w = 30, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3273, .adv_w = 326, .box_w = 20, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3343, .adv_w = 298, .box_w = 18, .box_h = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3406, .adv_w = 363, .box_w = 22, .box_h = 28, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 2,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 28,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t MachinePro80F = {
#else
lv_font_t MachinePro80F = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 30,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MACHINEPRO80F*/

