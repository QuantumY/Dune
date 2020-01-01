#ifndef DUNE_GENERAL_UTILITIES_H
#define DUNE_GENERAL_UTILITIES_H

#include <stdint.h>
#include <SDL.h>

#include "Dune/Logging/Basic.h"

namespace Dune
{	
	//Wait for ms milliseconds before returning
	void Wait(uint32_t ms);
}

#endif  /* DUNE_GENERAL_UTILITIES_H */
