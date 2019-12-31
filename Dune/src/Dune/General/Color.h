#ifndef DUNE_GENERAL_COLOR_H
#define DUNE_GENERAL_COLOR_H

#include <stdint.h>

//Create a ColorRGB based off a Color by removing the alpha
#define DUNE_COLOR_TO_COLORRGB(x) {x.red, x.green, x.blue}

//Take a Color and turn it into a 4 RGBA arguments
#define DUNE_COLOR_TO_RGBA(x) x.red, x.green, x.blue, x.alpha

//Create a Color based off a ColorRGB making it 100% opaque
#define DUNE_COLORRGB_TO_COLOR(x) {x.red, x.green, x.blue, 255}

//Take a ColorRGB and turn it into a 3 RGB arguments
#define DUNE_COLORRGB_TO_RGB(x) x.red, x.green, x.blue

namespace Dune
{
	typedef struct Color
	{
		uint32_t red;
		uint32_t green;
		uint32_t blue;
		uint32_t alpha;
	} Color;
	
	typedef struct ColorRGB
	{
		uint32_t red;
		uint32_t green;
		uint32_t blue;
	} Color_RGB;
}

#endif /* DUNE_GENERAL_COLOR_H */
