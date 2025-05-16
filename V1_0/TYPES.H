/*
	Some functions and definitions to ease development on MS-DOS systems.
	Version 1.0

	Author: Rafael Sabe
	Email: rafaelmsabe@gmail.com
*/

#ifndef TYPES_H
#define TYPES_H

#include <STDDEF.H>

#ifdef _Cdecl
#define __cdecl__ _Cdecl
#else
#define __cdecl__
#endif

#if(sizeof(void*) == 2u)
#define __PTR16
#else
#define __PTR32
#endif

#define __FALSE 0
#define __TRUE 1

typedef int __bool;

typedef char __char;
typedef int __int;
typedef long __long;

typedef unsigned char __uchar;
typedef unsigned int __uint;
typedef unsigned long __ulong;

typedef __char __int8;
typedef __int __int16;
typedef __long __int32;

typedef __uchar __uint8;
typedef __uint __uint16;
typedef __ulong __uint32;

typedef size_t __size;
typedef signed size_t __ssize;

typedef float __float32;
typedef double __float64;
typedef long double __float80;

typedef void* __ptr;
typedef void near* __nptr;
typedef void far* __fptr;
typedef void huge* __hptr;

typedef __bool* __ptr_bool;
typedef __bool near* __nptr_bool;
typedef __bool far* __fptr_bool;
typedef __bool huge* __hptr_bool;

typedef __char* __ptr_char;
typedef __char near* __nptr_char;
typedef __char far* __fptr_char;
typedef __char huge* __hptr_char;

typedef __int* __ptr_int;
typedef __int near* __nptr_int;
typedef __int far* __fptr_int;
typedef __int huge* __hptr_int;

typedef __long* __ptr_long;
typedef __long near* __nptr_long;
typedef __long far* __fptr_long;
typedef __long huge* __hptr_long;

typedef __uchar* __ptr_uchar;
typedef __uchar near* __nptr_uchar;
typedef __uchar far* __fptr_uchar;
typedef __uchar huge* __hptr_uchar;

typedef __uint* __ptr_uint;
typedef __uint near* __nptr_uint;
typedef __uint far* __fptr_uint;
typedef __uint huge* __hptr_uint;

typedef __ulong* __ptr_ulong;
typedef __ulong near* __nptr_ulong;
typedef __ulong far* __fptr_ulong;
typedef __ulong huge* __hptr_ulong;

typedef __int8* __ptr_int8;
typedef __int8 near* __nptr_int8;
typedef __int8 far* __fptr_int8;
typedef __int8 huge* __hptr_int8;

typedef __int16* __ptr_int16;
typedef __int16 near* __nptr_int16;
typedef __int16 far* __fptr_int16;
typedef __int16 huge* __hptr_int16;

typedef __int32* __ptr_int32;
typedef __int32 near* __nptr_int32;
typedef __int32 far* __fptr_int32;
typedef __int32 huge* __hptr_int32;

typedef __uint8* __ptr_uint8;
typedef __uint8 near* __nptr_uint8;
typedef __uint8 far* __fptr_uint8;
typedef __uint8 huge* __hptr_uint8;

typedef __uint16* __ptr_uint16;
typedef __uint16 near* __nptr_uint16;
typedef __uint16 far* __fptr_uint16;
typedef __uint16 huge* __hptr_uint16;

typedef __uint32* __ptr_uint32;
typedef __uint32 near* __nptr_uint32;
typedef __uint32 far* __fptr_uint32;
typedef __uint32 huge* __hptr_uint32;

typedef __size* __ptr_size;
typedef __size near* __nptr_size;
typedef __size far* __fptr_size;
typedef __size huge* __hptr_size;

typedef __ssize* __ptr_ssize;
typedef __ssize near* __nptr_ssize;
typedef __ssize far* __fptr_ssize;
typedef __ssize huge* __hptr_ssize;

typedef __float32* __ptr_float32;
typedef __float32 near* __nptr_float32;
typedef __float32 far* __fptr_float32;
typedef __float32 huge* __hptr_float32;

typedef __float64* __ptr_float64;
typedef __float64 near* __nptr_float64;
typedef __float64 far* __fptr_float64;
typedef __float64 huge* __hptr_float64;

typedef __float80* __ptr_float80;
typedef __float80 near* __nptr_float80;
typedef __float80 far* __fptr_float80;
typedef __float80 huge* __hptr_float80;

#endif /*TYPES_H*/
