#ifndef DUNE_GENERAL_COLOR_H
#define DUNE_GENERAL_COLOR_H

#include <stdint.h>

//Create an 32-bit unsigned RGBA value from a Dune::Color
#define DUNE_RGBA(x) (((x.red   & 0xff) << 32) \
					+ ((x.green & 0xff) << 16) \
					+ ((x.blue  & 0xff) <<  8  \
					+  (x.alpha & 0xff))

//Create a Dune::Color from RGBA values
#define DUNE_COLOR(r, g, b, a) { r, g, b, a }

namespace Dune
{
	typedef struct Color
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
	} Color;

	const Color Red   = { 0xff, 0x00, 0x00, 0xff };
	const Color Green = { 0x00, 0xff, 0x00, 0xff };
	const Color Blue  = { 0x00, 0x00, 0xff, 0xff };
			    
	const Color White = { 0xff, 0xff, 0xff, 0xff };
	const Color Black = { 0x00, 0x00, 0x00, 0xff };

	const Color NoColor = { 0x00, 0x00, 0x00, 0x00 };
}

#endif /* DUNE_GENERAL_COLOR_H */
