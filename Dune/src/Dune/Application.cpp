#include "Application.h"
#include "Dune/Logging/Basic.h"
#include "Dune/GUI/Window.h"

namespace Dune
{
	Application::Application(std::string name)
		:m_name(name), m_status(AppStatus::None)
	{
		//Don't use SDL's main function if SDL_MAIN_HANDLED is defined
		#ifdef SDL_MAIN_HANDLED
		SDL_SetMainReady();
		#endif /* SDL_MAIN_HANDLED */

		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			DUNE_BASIC_FATAL("SDL could not initialize properly");
		}
		else
		{
			DUNE_BASIC_LOG("SDL has been initialized");
		}

		Dune::Window window("My Window", Dune::WindowFlags::Fullscreen);

		auto props_copy = window.GetWindowProps();
		auto win_copy = window.GetSDL_Window();

		SDL_Rect rect;
		rect.w = 1000;
		rect.h = 1000;
		//Do some math to make positions relative to the center of the screen
		rect.x = 0 + (props_copy.width / 2) - (rect.w / 2);
		rect.y = -1 * 0 + (props_copy.height / 2) - (rect.h / 2);

		renderer = SDL_CreateRenderer(win_copy, -1, 0);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderDrawRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}

	Application::~Application()
	{
		//If app not yet been quit
		Quit();
	}

	void Application::Quit()
	{
		SDL_DestroyRenderer(renderer);

		if ((m_status & AppStatus::Quit) == false)
		{
			SDL_Quit();
			DUNE_BASIC_LOG("SDL has been quit");
		}
		else
		{
			DUNE_BASIC_WARN("Caling Dune::Application::Quit() more than once is not allowed");
		}

		m_status |= AppStatus::Quit;
	}
}
