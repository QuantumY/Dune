#include "Utilities.h"

namespace Dune
{
	void Wait(uint32_t ms)
	{
		DUNE_VA_LOG("Entering wait for %u seconds", ms);
		SDL_Delay(ms);
		DUNE_BASIC_LOG("Returning from wait");
	}
}
