#include "Application.h"
#include "Dune/Logging/Basic.h"

namespace Dune
{
	Application::Application(std::string name)
		:m_name(name), m_status(AppStatus::None)
	{
		//Don't use SDL's main function
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
	}

	Application::~Application()
	{
		//If app not yet been quit
		Quit();
	}

	void Application::Quit()
	{
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
