#ifndef DUNE_GRAPHICS_RECTANGLE_H
#define DUNE_GRAPHICS_RECTANGLE_H

#include <SDL.h>
#include <stdint.h>

#include "Color.h"

namespace Dune
{
	class Rectangle
	{
	public:
		uint32_t width, height;
		int x, y;
		//border and fill colors. These are ignored if their alphas are zero.
		Color border, fill;
		
		Rectangle();

		//set the width and height of the Rectangle.
		Rectangle(uint32_t width, uint32_t height);

		//set the width, height, x position, and y-position of the Rectangle.
		Rectangle(uint32_t width, uint32_t height, int x, int y);

		//set the width and height, and border color of the Rectangle. Optionally set the fill color
		Rectangle(uint32_t width, uint32_t height, Color border, Color fill = NoColor);

		//set the width, height, border color, x position, and y-position of the Rectangle. Optionally set the fill color
		Rectangle(uint32_t width, uint32_t height, int x, int y, Color border, Color fill = NoColor);

		//set equal to another rectangle
		inline Rectangle operator= (Rectangle rectangle);

		//scale the rectangle width and height by a coefficient (the outcome will be rounded)
		inline Rectangle operator *(float coefficient);

		//check if two rectangles have the same width and height
		bool operator== (Rectangle rectangle);

		~Rectangle();
	};
}

#endif /* DUNE_GRAPHICS_RECTANGLE_H */
