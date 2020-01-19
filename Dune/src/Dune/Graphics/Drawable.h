#ifndef DUNE_GRAPHICS_DRAWABLE_H
#define DUNE_GRAPHICS_DRAWABLE_H

#include "Dune/GUI/Views/View.h"

namespace Dune
{
	//all drawable/renderable object should inherit from this (directly or through virtual inheritance)
	class Drawable
	{
	protected:
		//Dune::View for rendering to
		View* view;
	public:

		//Draw to the renderer
		virtual void Draw() = 0;
	};
}

#endif /* DUNE_GRAPHICS_DRAWABLE_H */
