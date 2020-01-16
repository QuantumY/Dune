#ifndef DUNE_GUI_CANVAS_H
#define DUNE_GUI_CANVAS_H

#include <SDL.h>

#include "Window.h"
#include "Dune/Graphics/Color.h"

namespace Dune
{
	class Canvas
	{
	private:
		SDL_Renderer* m_renderer;
	public:
		//Create the canvas the same size as the window.
		//Arguments: the window, the rgb color to start with (in the window)
		Canvas(Dune::Window* window, Dune::ColorRGB init_color = {255, 255, 255});
		~Canvas();
	};
}

#endif /* DUNE_GUI_CANVAS_H */
