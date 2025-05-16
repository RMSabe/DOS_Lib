/*
	Some functions and definitions to ease development on MS-DOS systems.
	Version 1.0

	Author: Rafael Sabe
	Email: rafaelmsabe@gmail.com
*/

#include "CSTRDEF.H"

/*============================================================================================*/
/*_cstr variation functions*/

extern __ssize __cdecl__ _cstr_getlength_nptr(const __nptr_char str);
extern __ssize __cdecl__ _cstr_getlength_fptr(const __fptr_char str);

extern __bool __cdecl__ _cstr_compare_nptr_nptr(const __nptr_char str1, const __nptr_char str2);
extern __bool __cdecl__ _cstr_compare_nptr_fptr(const __nptr_char str1, const __fptr_char str2);
extern __bool __cdecl__ _cstr_compare_fptr_nptr(const __fptr_char str1, const __nptr_char str2);
extern __bool __cdecl__ _cstr_compare_fptr_fptr(const __fptr_char str1, const __fptr_char str2);

extern __bool __cdecl__ _cstr_copy_nptr_nptr(const __nptr_char input, __nptr_char output, __size bufferout_length);
extern __bool __cdecl__ _cstr_copy_nptr_fptr(const __nptr_char input, __fptr_char output, __size bufferout_length);
extern __bool __cdecl__ _cstr_copy_fptr_nptr(const __fptr_char input, __nptr_char output, __size bufferout_length);
extern __bool __cdecl__ _cstr_copy_fptr_fptr(const __fptr_char input, __fptr_char output, __size bufferout_length);

extern __bool __cdecl__ _cstr_tolower_nptr(__nptr_char str, __size buffer_length);
extern __bool __cdecl__ _cstr_tolower_fptr(__fptr_char str, __size buffer_length);

extern __bool __cdecl__ _cstr_toupper_nptr(__nptr_char str, __size buffer_length);
extern __bool __cdecl__ _cstr_toupper_fptr(__fptr_char str, __size buffer_length);

/*_cstr variation functions*/
/*===========================================================================================*/
/*_cstr pointer specific functions*/

__ssize __cdecl__ _cstr_getlength(__uint16 str_seg, __uint16 str_index, __bool str_fptr)
{
	if(str_fptr) return _cstr_getlength_fptr((__fptr_char) __FPTR_FROM_SEG_INDEX(str_seg, str_index));

	return _cstr_getlength_nptr((__nptr_char) str_index);
}

__bool __cdecl__ _cstr_compare(__uint16 str1_seg, __uint16 str1_index, __uint16 str2_seg, __uint16 str2_index, __bool str1_fptr, __bool str2_fptr)
{
	if(str1_fptr && str2_fptr) return _cstr_compare_fptr_fptr((__fptr_char) __FPTR_FROM_SEG_INDEX(str1_seg, str1_index), (__fptr_char) __FPTR_FROM_SEG_INDEX(str2_seg, str2_index));
	if(str1_fptr) return _cstr_compare_fptr_nptr((__fptr_char) __FPTR_FROM_SEG_INDEX(str1_seg, str1_index), (__nptr_char) str2_index);
	if(str2_fptr) return _cstr_compare_nptr_fptr((__nptr_char) str1_index, (__fptr_char) __FPTR_FROM_SEG_INDEX(str2_seg, str2_index));

	return _cstr_compare_nptr_nptr((__nptr_char) str1_index, (__nptr_char) str2_index);
}

__bool __cdecl__ _cstr_copy(__uint16 input_seg, __uint16 input_index, __uint16 output_seg, __uint16 output_index, __size bufferout_length, __bool input_fptr, __bool output_fptr)
{
	if(input_fptr && output_fptr) return _cstr_copy_fptr_fptr((__fptr_char) __FPTR_FROM_SEG_INDEX(input_seg, input_index), (__fptr_char) __FPTR_FROM_SEG_INDEX(output_seg, output_index), bufferout_length);
	if(input_fptr) return _cstr_copy_fptr_nptr((__fptr_char) __FPTR_FROM_SEG_INDEX(input_seg, input_index), (__nptr_char) output_index, bufferout_length);
	if(output_fptr) return _cstr_copy_nptr_fptr((__nptr_char) input_index, (__fptr_char) __FPTR_FROM_SEG_INDEX(output_seg, output_index), bufferout_length);

	return _cstr_copy_nptr_nptr((__nptr_char) input_index, (__nptr_char) output_index, bufferout_length);
}

__bool __cdecl__ _cstr_tolower(__uint16 str_seg, __uint16 str_index, __size buffer_length, __bool str_fptr)
{
	if(str_fptr) return _cstr_tolower_fptr((__fptr_char) __FPTR_FROM_SEG_INDEX(str_seg, str_index), buffer_length);

	return _cstr_tolower_nptr((__nptr_char) str_index, buffer_length);
}

__bool __cdecl__ _cstr_toupper(__uint16 str_seg, __uint16 str_index, __size buffer_length, __bool str_fptr)
{
	if(str_fptr) return _cstr_toupper_fptr((__fptr_char) __FPTR_FROM_SEG_INDEX(str_seg, str_index), buffer_length);

	return _cstr_toupper_nptr((__nptr_char) str_index, buffer_length);
}

/*_cstr pointer specific functions*/
/*==========================================================================================*/
/*cstr generic functions*/

__ssize __cdecl__ cstr_getlength(const __ptr_char str)
{

#ifdef __PTR16
	return _cstr_getlength_nptr((const __nptr_char) str);
#endif

#ifdef __PTR32
	return _cstr_getlength_fptr((const __fptr_char) str);
#endif

}

__bool __cdecl__ cstr_compare(const __ptr_char str1, const __ptr_char str2)
{

#ifdef __PTR16
	return _cstr_compare_nptr_nptr((const __nptr_char) str1, (const __nptr_char) str2);
#endif

#ifdef __PTR32
	return _cstr_compare_fptr_fptr((const __fptr_char) str1, (const __fptr_char) str2);
#endif

}

__bool __cdecl__ cstr_copy(const __ptr_char input, __ptr_char output, __size bufferout_length)
{
	if(bufferout_length < 1u) return __FALSE;

#ifdef __PTR16
	return _cstr_copy_nptr_nptr((const __nptr_char) input, (__nptr_char) output, bufferout_length);
#endif

#ifdef __PTR32
	return _cstr_copy_fptr_fptr((const __fptr_char) input, (__fptr_char) output, bufferout_length);
#endif

}

__bool __cdecl__ cstr_tolower(__ptr_char str, __size buffer_length)
{
	if(buffer_length < 1u) return __FALSE;

#ifdef __PTR16
	return _cstr_tolower_nptr((__nptr_char) str, buffer_length);
#endif

#ifdef __PTR32
	return _cstr_tolower_fptr((__fptr_char) str, buffer_length);
#endif

}

__bool __cdecl__ cstr_toupper(__ptr_char str, __size buffer_length)
{
	if(buffer_length < 1u) return __FALSE;

#ifdef __PTR16
	return _cstr_toupper_nptr((__nptr_char) str, buffer_length);
#endif

#ifdef __PTR32
	return _cstr_toupper_fptr((__fptr_char) str, buffer_length);
#endif

}

/*cstr generic functions*/
/*===========================================================================================*/
/*_cstr_getlength variations*/

__ssize __cdecl__ _cstr_getlength_nptr(const __nptr_char str)
{
	__size len = 0u;

	while(str[len] != '\0') len++;

	return (__ssize) len;
}

__ssize __cdecl__ _cstr_getlength_fptr(const __fptr_char str)
{
	__size len = 0u;

	while(str[len] != '\0') len++;

	return (__ssize) len;
}

/*_cstr_getlength variations*/
/*=========================================================================================*/
/*_cstr_compare variations*/

__bool __cdecl__ _cstr_compare_nptr_nptr(const __nptr_char str1, const __nptr_char str2)
{
	__size len1;
	__size len2;

	len1 = (__size) _cstr_getlength_nptr(str1);
	len2 = (__size) _cstr_getlength_nptr(str2);

	if(len1 != len2) return __FALSE;

	len1 = 0u;

	while(len1 < len2)
	{
		if(str1[len1] != str2[len1]) return __FALSE;
		len1++;
	}

	return __TRUE;
}

__bool __cdecl__ _cstr_compare_nptr_fptr(const __nptr_char str1, const __fptr_char str2)
{
	__size len1;
	__size len2;

	len1 = (__size) _cstr_getlength_nptr(str1);
	len2 = (__size) _cstr_getlength_fptr(str2);

	if(len1 != len2) return __FALSE;

	len1 = 0u;

	while(len1 < len2)
	{
		if(str1[len1] != str2[len1]) return __FALSE;
		len1++;
	}

	return __TRUE;
}

__bool __cdecl__ _cstr_compare_fptr_nptr(const __fptr_char str1, const __nptr_char str2)
{
	__size len1;
	__size len2;

	len1 = (__size) _cstr_getlength_fptr(str1);
	len2 = (__size) _cstr_getlength_nptr(str2);

	if(len1 != len2) return __FALSE;

	len1 = 0u;

	while(len1 < len2)
	{
		if(str1[len1] != str2[len1]) return __FALSE;
		len1++;
	}

	return __TRUE;
}

__bool __cdecl__ _cstr_compare_fptr_fptr(const __fptr_char str1, const __fptr_char str2)
{
	__size len1;
	__size len2;

	len1 = (__size) _cstr_getlength_fptr(str1);
	len2 = (__size) _cstr_getlength_fptr(str2);

	if(len1 != len2) return __FALSE;

	len1 = 0u;

	while(len1 < len2)
	{
		if(str1[len1] != str2[len1]) return __FALSE;
		len1++;
	}

	return __TRUE;
}

/*_cstr_compare variations*/
/*=========================================================================================*/
/*_cstr_copy variations*/

__bool __cdecl__ _cstr_copy_nptr_nptr(const __nptr_char input, __nptr_char output, __size bufferout_length)
{
	__size input_len;
	__size stop_index;
	__size n_char;

	if(bufferout_length < 1u) return __FALSE;

	input_len = _cstr_getlength_nptr(input);

	if(input_len < bufferout_length) stop_index = input_len;
	else stop_index = bufferout_length - 1u;

	n_char = 0u;
	while(n_char < stop_index)
	{
		output[n_char] = input[n_char];
		n_char++;
	}

	output[stop_index] = '\0';

	return (input_len < bufferout_length);
}

__bool __cdecl__ _cstr_copy_nptr_fptr(const __nptr_char input, __fptr_char output, __size bufferout_length)
{
	__size input_len;
	__size stop_index;
	__size n_char;

	if(bufferout_length < 1u) return __FALSE;

	input_len = _cstr_getlength_nptr(input);

	if(input_len < bufferout_length) stop_index = input_len;
	else stop_index = bufferout_length - 1u;

	n_char = 0u;
	while(n_char < stop_index)
	{
		output[n_char] = input[n_char];
		n_char++;
	}

	output[stop_index] = '\0';

	return (input_len < bufferout_length);
}

__bool __cdecl__ _cstr_copy_fptr_nptr(const __fptr_char input, __nptr_char output, __size bufferout_length)
{
	__size input_len;
	__size stop_index;
	__size n_char;

	if(bufferout_length < 1u) return __FALSE;

	input_len = _cstr_getlength_fptr(input);

	if(input_len < bufferout_length) stop_index = input_len;
	else stop_index = bufferout_length - 1u;

	n_char = 0u;
	while(n_char < stop_index)
	{
		output[n_char] = input[n_char];
		n_char++;
	}

	output[stop_index] = '\0';

	return (input_len < bufferout_length);
}

__bool __cdecl__ _cstr_copy_fptr_fptr(const __fptr_char input, __fptr_char output, __size bufferout_length)
{
	__size input_len;
	__size stop_index;
	__size n_char;

	if(bufferout_length < 1u) return __FALSE;

	input_len = _cstr_getlength_fptr(input);

	if(input_len < bufferout_length) stop_index = input_len;
	else stop_index = bufferout_length - 1u;

	n_char = 0u;
	while(n_char < stop_index)
	{
		output[n_char] = input[n_char];
		n_char++;
	}

	output[stop_index] = '\0';

	return (input_len < bufferout_length);
}

/*_cstr_copy variations*/
/*=========================================================================================*/
/*_cstr_tolower variations*/

__bool __cdecl__ _cstr_tolower_nptr(__nptr_char str, __size buffer_length)
{
	__size len;
	__size nchar;

	if(buffer_length < 1u) return __FALSE;

	str[buffer_length - 1u] = '\0';

	len = (__size) _cstr_getlength_nptr(str);

	nchar = 0u;
	while(nchar < len)
	{
		if((str[nchar] >= 0x41) && (str[nchar] <= 0x5a)) str[nchar] |= 0x20;
		nchar++;
	}

	return __TRUE;
}

__bool __cdecl__ _cstr_tolower_fptr(__fptr_char str, __size buffer_length)
{
	__size len;
	__size nchar;

	if(buffer_length < 1u) return __FALSE;

	str[buffer_length - 1u] = '\0';

	len = (__size) _cstr_getlength_fptr(str);

	nchar = 0u;
	while(nchar < len)
	{
		if((str[nchar] >= 0x41) && (str[nchar] <= 0x5a)) str[nchar] |= 0x20;
		nchar++;
	}

	return __TRUE;
}

/*_cstr_tolower variations*/
/*=========================================================================================*/
/*_cstr_toupper variations*/

__bool __cdecl__ _cstr_toupper_nptr(__nptr_char str, __size buffer_length)
{
	__size len;
	__size nchar;

	if(buffer_length < 1u) return __FALSE;

	str[buffer_length - 1u] = '\0';

	len = (__size) _cstr_getlength_nptr(str);

	nchar = 0u;
	while(nchar < len)
	{
		if((str[nchar] >= 0x61) && (str[nchar] <= 0x7a)) str[nchar] &= 0xdf;
		nchar++;
	}

	return __TRUE;
}

__bool __cdecl__ _cstr_toupper_fptr(__fptr_char str, __size buffer_length)
{
	__size len;
	__size nchar;

	if(buffer_length < 1u) return __FALSE;

	str[buffer_length - 1u] = '\0';

	len = (__size) _cstr_getlength_fptr(str);

	nchar = 0u;
	while(nchar < len)
	{
		if((str[nchar] >= 0x61) && (str[nchar] <= 0x7a)) str[nchar] &= 0xdf;
		nchar++;
	}

	return __TRUE;
}

/*_cstr_toupper variations*/
/*=========================================================================================*/

