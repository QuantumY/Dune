#ifndef DUNE_APPLICATION_H
#define DUNE_APPLICATION_H

#include <string>

namespace Dune
{
	class Application
	{
	private:
		std::string name;

		void Quit();
	public:
		//
		//Create the application. Arguments: application name
		Application(std::string);
		~Application();
	};
}

#endif /* DUNE_APPLICATION_H */
