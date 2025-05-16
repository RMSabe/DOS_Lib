/*
	Some functions and definitions to ease development on MS-DOS systems.
	Version 1.0

	Author: Rafael Sabe
	Email: rafaelmsabe@gmail.com
*/

#include "GLOBLDEF.H"

__char textbuf[TEXTBUF_SIZE_CHARS] = {'\0'};

__size __cdecl__ _get_closest_power2_round(__size input)
{
	__size limit;
	__size max;
	__size size1;
	__size size2;

	if(!input) return 0u;
	if(_is_power2(input)) return input;

	limit = _get_size_msb_value();
	max = _get_size_max_value();

	if(input > limit)
	{
		size2 = max - input;
		size1 = input - limit;

		if(size1 < size2) return limit;

		return 0u;
	}

	size2 = _get_closest_power2_ceil(input);
	size1 = (size2 >> 1);

	if((input - size1) < (size2 - input)) return size1;

	return size2;
}

__size __cdecl__ _get_closest_power2_floor(__size input)
{
	__size limit;
	__size size;

	if(!input) return 0u;
	if(_is_power2(input)) return input;

	limit = _get_size_msb_value();

	if(input > limit) return limit;

	size = _get_closest_power2_ceil(input);
	size = (size >> 1);

	return size;
}

__size __cdecl__ _get_closest_power2_ceil(__size input)
{
	__size limit;
	__size size;

	if(!input) return 0u;
	if(_is_power2(input)) return input;

	limit = _get_size_msb_value();

	if(input > limit) return 0u;

	size = 1u;
	while(size < limit)
	{
		if(!(input/size)) break;
		size = (size << 1);
	}

	return size;
}

__bool __cdecl__ _is_power2(__size input)
{
	__size limit;
	__size size;

	if(!input) return __FALSE;

	limit = _get_size_msb_value();

	if(input == limit) return __TRUE;
	if(input > limit) return __FALSE;

	size = 1u;
	while(size < limit)
	{
		if(input == size) return __TRUE;
		size = (size << 1);
	}

	return __FALSE;
}

__size __cdecl__ _get_size_max_value(void)
{
	__size size;

	size ^= size;
	size = ~size;

	return size;
}

__size __cdecl__ _get_size_msb_value(void)
{
	__size size;

	size ^= size;
	size = ~size;
	size = (size >> 1);
	size = ~size;

	return size;
}
