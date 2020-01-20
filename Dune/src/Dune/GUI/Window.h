#ifndef DUNE_GUI_WINDOW_H
#define DUNE_GUI_WINDOW_H

#include <SDL.h>
#include <string>
#include <utility>

#include "Dune/Logging/Basic.h"
#include "Dune/Graphics/Primitives/Rectangle.h"
//#include "Canvas.h"

#define DUNE_WINDOW_CENTERED SDL_WINDOWPOS_CENTERED

#define DUNE_WINDOW_FULLSCREEN SDL_WINDOW_FULLSCREEN

namespace Dune
{
	//Aliases of SDL window flags. Use bitwize OR (|) to use multiple flags. 
	//!INCOMPLETE
	enum WindowFlags
	{
		Resizable = SDL_WINDOW_RESIZABLE,
		Shown = SDL_WINDOW_SHOWN,
		Hidden = SDL_WINDOW_HIDDEN,
		Borderless = SDL_WINDOW_BORDERLESS,
		//special flag
		Minimized = SDL_WINDOW_MINIMIZED,
		//special flag
		Maximized = SDL_WINDOW_MAXIMIZED,
		//proper fullscreen mode
		//special flag
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
		std::string m_title;
		Rectangle m_rectangle;
		SDL_Window* m_window;
	public:

		//!INCOMPLETE: This function is a work in progress
		//Create the window in the center of the screen with special flags.
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

		//Create the window based off an already created SDL_Window (pointer)
		Window(SDL_Window* window);

		//Show the window (if hidden)
		void ShowWindow();
		
		//Hide the window
		void HideWindow();

		//Returns a pointer to the SDL_Window
		inline SDL_Window* GetSDL_Window() { return m_window; }
		
		//Set the window title
		void SetTitle(std::string title);

		std::string GetTitle() { return m_title; }

		//Get the window width and height
		Rectangle GetDimensions() { return m_rectangle; };

		//Make the window fullscreen
		void SetFullscreen();

		//Close the window.
		void Close();

		~Window();
	};
}

#endif /* DUNE_GUI_WINDOW_H */
