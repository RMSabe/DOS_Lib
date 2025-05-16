/*
	Some functions and definitions to ease development on MS-DOS systems.
	Version 1.0

	Author: Rafael Sabe
	Email: rafaelmsabe@gmail.com
*/

#ifndef GLOBLDEF_H
#define GLOBLDEF_H

#include "TYPES.H"

#define __FPTR_GET_SEG(fptr) ((__uint16) (((__uint32) fptr) >> 16))
#define __FPTR_GET_INDEX(fptr) ((__uint16) fptr)
#define __FPTR_FROM_SEG_INDEX(seg, index) ((__fptr) ((((__uint32) seg) << 16) | ((__uint32) index)))
#define __HPTR_FROM_SEG_INDEX(seg, index) ((__hptr) ((((__uint32) seg) << 4) | ((__uint32) index)))

#define TEXTBUF_SIZE_CHARS 256U
#define TEXTBUF_SIZE_BYTES TEXTBUF_SIZE_CHARS

extern __char textbuf[];

extern __size __cdecl__ _get_closest_power2_round(__size input);
extern __size __cdecl__ _get_closest_power2_floor(__size input);
extern __size __cdecl__ _get_closest_power2_ceil(__size input);

extern __bool __cdecl__ _is_power2(__size input);

extern __size __cdecl__ _get_size_max_value(void);
extern __size __cdecl__ _get_size_msb_value(void);

#endif /*GLOBLDEF_H*/
