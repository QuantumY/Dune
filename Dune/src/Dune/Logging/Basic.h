#ifndef DUNE_LOGGING_BASIC_H
#define DUNE_LOGGING_BASIC_H

#ifdef DUNE_VS2019
//For __debugbreak()
#include <intrin.h>
#endif /* DUNE_VS2019 */

#include <cstdlib>

/*
	Extremely basic console logging with macros. 
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
#define DUNE_PRINT_GREEN  "\u001b[32m"

#elif defined DUNE_PLATFORM_MAC || DUNE_PLATFORM_LINUX

/*
	ANSI colors for Mac and Linux. Note that these are untested.  
*/
#define DUNE_PRINT_BLACK  "\[\033[0;34m\]"
#define DUNE_PRINT_RED    "\[\033[0;31m\]"
#define DUNE_PRINT_YELLOW "\[\033[1;33m\]"
#define DUNE_PRINT_WHITE  "\[\033[1;37m\]"
#define DUNE_PRINT_GREEN  "\[\033[1;32m\]"

#endif /* DUNE_PLATFORM_WINDOWS  */

#ifdef DUNE_DEBUG
	#define DUNE_BASIC_PRINT(color, append, message) printf("%s%s%s\n", color, append, message)
	#ifdef DUNE_COMPILER_MSVC
		#define DUNE_BREAKPOINT() __debugbreak()
	#elif defined DUNE_COMPILER_GCC
		#define DUNE_BREAKPOINT() __builtin_trap()
	#endif /* DUNE_PLATFORM_WINDOWS */
	#ifdef DUNE_EXIT_ON_FATAL_ERROR
		//Display a fatal error on the console window in green text and quit Dune
		#define DUNE_BASIC_FATAL(x) DUNE_BASIC_PRINT(DUNE_PRINT_GREEN, "[ FATAL ]", x); std::exit(-1)
	#else
		//Display a fatal error on the console window in green text and make a breakpoint
		#define DUNE_BASIC_FATAL(x) DUNE_BASIC_PRINT(DUNE_PRINT_GREEN, "[ FATAL ]", x); DUNE_BREAKPOINT()
	#endif /* DUNE_EXIT_ON_FATAL_ERROR */
#elif defined DUNE_RELEASE
	#define DUNE_BASIC_PRINT(color, append, message)

	//Display a fatal error on the console window in green text and make a breakpoint
	#define DUNE_BASIC_FATAL(x)
#endif /* DUNE_DEBUG */

//Display an error on the console window in red text (Debug)
#define DUNE_BASIC_ERROR(x) DUNE_BASIC_PRINT(DUNE_PRINT_RED, "[ ERROR ] ", x)

//Display a warning on the console window in yellow text (Debug)
#define DUNE_BASIC_WARN(x) DUNE_BASIC_PRINT(DUNE_PRINT_YELLOW, "[WARNING] ", x)

//Log information on the console window in white text (Debug)
#define DUNE_BASIC_LOG(x) DUNE_BASIC_PRINT(DUNE_PRINT_WHITE, "[  LOG  ] ", x)

#endif /* DUNE_LOGGING_BASIC_H */
