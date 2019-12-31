#include "Canvas.h"

namespace Dune
{
	//!INCOMPLETE: SDL_CreateRenderer arguments
	Canvas::Canvas(Dune::Window* window, Dune::Color init_color)
	{
		//Create the SDL_Renderer based off the size of the window
		//(we want them to be the same size)
		m_renderer = SDL_CreateRenderer(window->m_window, -1, 0);

		//Initialization color
		SDL_SetRenderDrawColor(m_renderer, DUNE_COLOR_TO_RGBA(init_color));
		SDL_RenderClear(m_renderer);
		SDL_RenderPresent(m_renderer);
	}
}
