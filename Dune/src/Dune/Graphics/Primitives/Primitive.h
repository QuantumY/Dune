#ifndef DUNE_GRAPHICS_PRIMITIVES_PRIMITIVE_H
#define DUNE_GRAPHICS_PRIMITIVES_PRIMITIVE_H

#include <stdint.h>

#include "Dune/Graphics/Color.h"

namespace Dune
{
	//Class that all graphics primitives inherit from
	class Primitive //: public virtual Drawable
	{
	protected:
		uint32_t width, height;
		int x, y;
		//border and fill colors. These are ignored if their alphas are zero.
		Color border, fill;
	public:
		virtual inline Primitive operator=(Primitive);
	};
}

#endif /* DUNE_GRAPHICS_PRIMITIVES_PRIMITIVE_H */
