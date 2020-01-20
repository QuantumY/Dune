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

	//Always create an instance of this before you do any other Dune related stuff.
	//This initializes SDL for graphics rendering
	class Application
	{
	private:
		std::string m_name;
		uint32_t m_status;

		void Quit();
	public:
		//Create the application (with a name)
		Application(std::string name);

		~Application();
	};
}

#endif /* DUNE_APPLICATION_H */
