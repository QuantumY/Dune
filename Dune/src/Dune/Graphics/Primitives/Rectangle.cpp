#include "Rectangle.h"

namespace Dune
{
	Rectangle::Rectangle()
		: x(0), y(0), width(0), height(0), border(Dune::Black), fill(Dune::NoColor)
	{

	}

	Rectangle::Rectangle(uint32_t width, uint32_t height)
		: x(0), y(0), width(width), height(height), border(Dune::Black), fill(Dune::NoColor)
	{

	}

	Rectangle::Rectangle(uint32_t width, uint32_t height, int x, int y)
		: x(x), y(y), width(width), height(height), border(Dune::Black), fill(Dune::NoColor)
	{

	}

	Rectangle::Rectangle(uint32_t width, uint32_t height, Color border, Color fill)
		: x(0), y(0), width(width), height(height), border(border), fill(fill)
	{

	}

	Rectangle::Rectangle(uint32_t width, uint32_t height, int x, int y, Color border, Color fill)
		:x(x), y(y), width(width), height(height), border(border), fill(fill)
	{

	}

	inline Rectangle Rectangle::operator=(Rectangle rectangle)
	{
		return rectangle;
	}

	inline Rectangle Rectangle::operator*(float coefficient)
	{
		return Rectangle(width * coefficient, height * coefficient);
	}

	bool Rectangle::operator== (Rectangle rectangle)
	{
		//check that the two rectangles are equal in size, if they are, return true. 
		if ((rectangle.width == width) && (rectangle.height == rectangle.height)) return true;

		//return false if they aren't equal
		return false;
	}

	Rectangle::~Rectangle()
	{

	}
}
