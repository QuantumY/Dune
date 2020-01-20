#ifndef DUNE_H
#define DUNE_H

/*
#define DUNE_PLATFORM_WINDOWS
#define DUNE_PLATFORM_X64
#define DUNE_COMPILE_STATIC
#define DUNE_DEBUG
#define DUNE_EXIT_ON_FATAL_ERROR
*/

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "Dune/Application.h"

//GUI headers
#include "Dune/GUI/Window.h"
//#include "Dune/GUI/Canvas.h"

//General headers
#include "Dune/General/Color.h"
#include "Dune/General/Utilities.h"

#endif /* DUNE_H */
