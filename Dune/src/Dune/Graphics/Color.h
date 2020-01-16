#ifndef DUNE_GENERAL_COLOR_H
#define DUNE_GENERAL_COLOR_H

#include <stdint.h>

namespace Dune
{
	typedef struct Color
	{
		uint32_t red;
		uint32_t green;
		uint32_t blue;
		uint32_t alpha;
	} Color;

	const Color Red   = { 0xff, 0x00, 0x00 };
	const Color Green = { 0x00, 0xff, 0x00 };
	const Color Blue  = { 0x00, 0x00, 0xff };
			    
	const Color White = { 0xff, 0xff, 0xff };
	const Color Black = { 0x00, 0x00, 0x00 };

	const Color NoColor = { 0x00, 0x00, 0x00, 0x00 };
}

#endif /* DUNE_GENERAL_COLOR_H */
