#define DUNE_PLATFORM_WINDOWS
#define DUNE_PLATFORM_X64
#define DUNE_COMPILE_STATIC
#define DUNE_DEBUG

#include "Dune.h"

int main()
{
	Dune::Application app("My App");
	return 0;
}
