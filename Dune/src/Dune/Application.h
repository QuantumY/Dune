#ifndef DUNE_APPLICATION_H
#define DUNE_APPLICATION_H

#include <SDL.h>
#include <string>
#include <stdint.h>
#include <cstdlib>

#define DUNE_APPSTATUS_NONE 0x00
#define DUNE_APPSTATUS_QUIT 0x01

namespace Dune
{
	class Application
	{
	private:
		std::string name;
		uint32_t status;

		void Quit();
	public:
		//
		//Create the application. Arguments: application name
		Application(std::string);
		~Application();
	};
}

#endif /* DUNE_APPLICATION_H */
