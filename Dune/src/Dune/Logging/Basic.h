#ifndef DUNE_BASIC_H
#define DUNE_BASIC_H

#include <iostream>

/*
	Extremely basic macro logging. 
	Log file(s) not yet supported.
*/

#ifdef DUNE_PLATFORM_WINDOWS
#define DUNE_PRINT_COLORS

/*
	Unicode colors for Command Prompt
*/
#define DUNE_PRINT_BLACK  "\u001b[30m"
#define DUNE_PRINT_RED    "\u001b[31m"
#define DUNE_PRINT_YELLOW "\u001b[33m"
#define DUNE_PRINT_WHITE  "\u001b[37m"

#elif defined DUNE_PLATFORM_MAC || DUNE_PLATFORM_LINUX

/*
	ANSI colors for Mac and Linux. Note that these are untested.  
*/
#define DUNE_PRINT_BLACK  "\[\033[0;34m\]"
#define DUNE_PRINT_RED    "\[\033[0;31m\]"
#define DUNE_PRINT_YELLOW "\[\033[1;33m\]"
#define DUNE_PRINT_WHITE  "\[\033[1;37m\]"

#endif /* DUNE_PLATFORM_WINDOWS  */

#ifdef DUNE_DEBUG
	#ifdef DUNE_PLATFORM_WINDOWS

		//Error in red text
		#define DUNE_BASIC_ERROR(x) std::cout << DUNE_PRINT_RED <<"[ ERROR ] " << x << std::endl

		//Warning in yellow text
		#define DUNE_BASIC_WARN(x) std::cout << DUNE_PRINT_YELLOW << "[WARNING] " << x << std::endl

		//Log in white text
		#define DUNE_BASIC_LOG(x) std::cout << DUNE_PRINT_WHITE << "[  LOG  ] " << x << std::endl

	#endif /* DUNE_PLATFORM_WINDOWS */
#elif defined DUNE_RELEASE
	#define DUNE_BASIC_ERROR(x)
	#define DUNE_BASIC_WARN(x)
	#define DUNE_BASIC_LOG(x)
#endif /* DUNE_DEBUG */

#endif /* DUNE_BASIC_H */
