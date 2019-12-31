#ifndef DUNE_GUI_WINDOW_H
#define DUNE_GUI_WINDOW_H

#include <SDL.h>
#include <string>

#include "Dune/Logging/Basic.h"
//#include "Canvas.h"

#define DUNE_WINDOW_CENTERED SDL_WINDOWPOS_CENTERED

#define DUNE_WINDOW_FULLSCREEN SDL_WINDOW_FULLSCREEN

namespace Dune
{
	//Data for settings up/storing the data of the window. 
	struct WindowProps
	{
		std::string title;
		uint32_t x, y;
		uint32_t width, height;
	};

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
		//proper fullscreen mode
		Fullscreen = SDL_WINDOW_FULLSCREEN,
		//Desktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
		Popup = SDL_WINDOW_POPUP_MENU,
		Top = SDL_WINDOW_ALWAYS_ON_TOP,
		Default = Resizable | Shown
	};

	class Window
	{
		//friend Dune::Canvas;
	private:
		WindowProps m_props;
		SDL_Window* m_window;
	public:

		//Create the window in the center of the screen with certain flags.
		//Use this to create a fullscreen window using WindowFlags::Fullscreen
		Window(std::string title, uint32_t flags = WindowFlags::Default);

		//Create the window in the center of the screen
		//Do not use this to create a fullscreen window
		Window(std::string title, uint32_t width, uint32_t height, 
			uint32_t flags = WindowFlags::Default);
		
		//Create the window in the position specified
		//(Use DUNE_WINDOW_CENTERED for x and y if you want the window to be centered)
		//Do not use this method to create a fullscreen window
		Window(std::string title, uint32_t x, uint32_t y, uint32_t width, 
			uint32_t height, uint32_t flags = WindowFlags::Default);
		
		//Create the window using a WindowProps object
		Window(WindowProps props, uint32_t flags = WindowFlags::Default);

		//Show the window (if hidden)
		void ShowWindow();
		
		//Hide the window
		void HideWindow();

		//Returns the SDL_Window
		SDL_Window* GetSDL_Window();
		
		//Returns a copy of m_props
		WindowProps GetWindowProps();

		//Make the window fullscreen
		void MakeWindowFullscreen();

		~Window();
	};
}

#endif /* DUNE_GUI_WINDOW_H */
