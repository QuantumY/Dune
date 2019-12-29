#ifndef DUNE_APPLICATION_H
#define DUNE_APPLICATION_H

#include <SDL.h>
#include <string>
#include <stdint.h>
#include <cstdlib>

namespace Dune
{
	enum AppStatus
	{
		None = 0,		//none
		Quit = 0x01		//has already been quit
	};

	class Application
	{
	private:
		std::string m_name;
		uint32_t m_status;

		void Quit();
	public:
		//
		//Create the application
		Application(std::string name);
		~Application();
	};
}

#endif /* DUNE_APPLICATION_H */
