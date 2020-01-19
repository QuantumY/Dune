#ifndef DUNE_GUI_VIEWS_VIEW_H
#define DUNE_GUI_VIEWS_VIEW_H

#include <vector>
#include <string>
#include <stdint.h>
#include <SDL.h>

#include "Dune/Logging/Basic.h"

namespace Dune
{
	//foward declaration for Dune/Graphics/Drawable.h (class Dune::Drawable)
	class Drawable;

	//All views (e.g. Canvas) should inherit from this class
	class View
	{
	protected:
		//SDL_Renderer for rendering
		SDL_Renderer* m_renderer;

		//All drawable objects stored as a vector
		std::vector<Drawable*> m_drawables;

		//Dune menubar which effects the rendering size of the renderer (Mac vs. Windows)
		//Menubar* menubar;

		std::string m_title;

	public:
		//function to draw all object in the renderer (and the menubar)
		//This function is virtual because different views render differently (e.g. relative to center vs. top left)
		virtual void Draw() = 0;

		//Essentialy just destroyes the SDL_Renderer (called by the deconstructor or user)
		void Destroy();
	};
}

#endif /* DUNE_GUI_VIEWS_VIEW_H */
