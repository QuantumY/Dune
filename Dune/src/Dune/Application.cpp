#include "Application.h"

namespace Dune
{
	Application::Application(std::string app_name)
	{
		name = app_name;
	}

	Application::~Application()
	{
		Quit();
	}

	void Application::Quit()
	{

	}
}
