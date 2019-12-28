#include "Application.h"
#include "Logging/Basic.h"

namespace Dune
{
	Application::Application(std::string app_name)
		:name(app_name), status(DUNE_APPSTATUS_NONE)
	{
		//Don't use SDL's main function
		#ifdef SDL_MAIN_HANDLED
		SDL_SetMainReady();
		#endif /* SDL_MAIN_HANDLED */

		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			DUNE_BASIC_FATAL("SDL2 could not initialize properly");
			Quit();
		}
	}

	Application::~Application()
	{
		DUNE_BASIC_LOG("Dune::Application::~Application() has been called");
		Quit();
	}

	void Application::Quit()
	{
		DUNE_BASIC_LOG("Dune::Application::Quit() has been called");
		if (status != DUNE_APPSTATUS_QUIT)
		{
			SDL_Quit();
			status = DUNE_APPSTATUS_QUIT;
			DUNE_BASIC_LOG("SDL has been quit");
		}
		else
		{
			DUNE_BASIC_WARN("Caling Dune::Application::Quit() more than once is not allowed");
		}
	}
}
