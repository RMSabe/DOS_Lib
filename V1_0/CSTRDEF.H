/*
	Some functions and definitions to ease development on MS-DOS systems.
	Version 1.0

	Author: Rafael Sabe
	Email: rafaelmsabe@gmail.com
*/

#ifndef CSTRDEF_H
#define CSTRDEF_H

#include "GLOBLDEF.H"

extern __ssize __cdecl__ _cstr_getlength(__uint16 str_seg, __uint16 str_index, __bool str_fptr);

extern __bool __cdecl__ _cstr_compare(__uint16 str1_seg, __uint16 str1_index, __uint16 str2_seg, __uint16 str2_index, __bool str1_fptr, __bool str2_fptr);

extern __bool __cdecl__ _cstr_copy(__uint16 input_seg, __uint16 input_index, __uint16 output_seg, __uint16 output_index, __size bufferout_length, __bool input_fptr, __bool output_fptr);

extern __bool __cdecl__ _cstr_tolower(__uint16 str_seg, __uint16 str_index, __size buffer_length, __bool str_fptr);
extern __bool __cdecl__ _cstr_toupper(__uint16 str_seg, __uint16 str_index, __size buffer_length, __bool str_fptr);

extern __ssize __cdecl__ cstr_getlength(const __ptr_char str);
extern __bool __cdecl__ cstr_compare(const __ptr_char str1, const __ptr_char str2);
extern __bool __cdecl__ cstr_copy(const __ptr_char input, __ptr_char output, __size bufferout_length);
extern __bool __cdecl__ cstr_tolower(__ptr_char str, __size buffer_length);
extern __bool __cdecl__ cstr_toupper(__ptr_char str, __size buffer_length);

#endif /*CSTRDEF_H*/
