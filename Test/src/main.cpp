#define DUNE_PLATFORM_WINDOWS
#define DUNE_PLATFORM_X64
#define DUNE_COMPILE_STATIC
#define DUNE_DEBUG
#define DUNE_EXIT_ON_FATAL_ERROR

#include "Dune.h"

int main(int argc, char* args[])
{
	Dune::Application app("My App");
	return 0;
}
