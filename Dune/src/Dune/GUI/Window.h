#ifndef DUNE_GUI_WINDOW_H
#define DUNE_GUI_WINDOW_H

#include <SDL.h>
#include <string>

#include "Dune/Logging/Basic.h"

#define DUNE_WINDOW_CENTERED SDL_WINDOWPOS_CENTERED

namespace Dune
{
	//
	//Data for settings up/storing the data of the window. 
	struct WindowProps
	{
		std::string title;
		uint32_t x, y;
		uint32_t width, height;
	};

	//
	//Aliases of SDL window flags. Use bitwize OR (|) to use multiple flags. 
	//!INCOMPLETE
	enum WindowFlags
	{
		Resizable = SDL_WINDOW_RESIZABLE,
		Shown = SDL_WINDOW_SHOWN,
		Hidden = SDL_WINDOW_HIDDEN,
		Borderless = SDL_WINDOW_BORDERLESS,
		Minimized = SDL_WINDOW_MINIMIZED,
		Maximized = SDL_WINDOW_MAXIMIZED,
		Popup = SDL_WINDOW_POPUP_MENU,
		Fullscreen = SDL_WINDOW_FULLSCREEN,
		Desktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
		Top = SDL_WINDOW_ALWAYS_ON_TOP,
		Default = Resizable | Shown
	};

	//
	//!INCOMPLETE
	class Window
	{
	private:
		SDL_Window* m_window;
		WindowProps m_props;
	public:
		//
		//Create the window in the center of the screen
		Window(std::string title, uint32_t width, uint32_t height);
		//
		//Create the window in the center of the screen
		Window(std::string title, uint32_t width, uint32_t height, uint32_t flags);
		//
		//Create the window
		Window(std::string title, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
		//
		//Create the window
		Window(std::string title, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t flags);
		//
		//Create the window using a WindowProps object
		Window(WindowProps props);
		//
		//Create the window using a WindowProps object
		Window(WindowProps props, uint32_t flags);
		//
		//Returns a copy of the WindowProps
		WindowProps GetWindowProps();
		~Window();
	};
}

#endif /* DUNE_GUI_WINDOW_H */
