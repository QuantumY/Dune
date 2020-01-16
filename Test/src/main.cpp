/*
#define DUNE_PLATFORM_WINDOWS
#define DUNE_PLATFORM_X64
#define DUNE_COMPILE_STATIC
#define DUNE_DEBUG
#define DUNE_EXIT_ON_FATAL_ERROR
*/

#include "Dune.h"
#include <SDL2_gfxPrimitives.h>

int main(int argc, char* args[])
{
	Dune::Application app("My App");
	Dune::Window window("My Window", Dune::WindowFlags::Fullscreen);

	Dune::Rectangle dimensions = window.getDimensions();
	SDL_Window* win_ptr = window.getSDL_Window();

	SDL_Rect rect;
	rect.w = 1000;
	rect.h = 1000;
	//Do some math to make positions relative to the center of the screen
	rect.x = 0 + (dimensions.width / 2) - (rect.w/2);
	rect.y = -1 * 0 + (dimensions.height / 2) - (rect.h/2);

	SDL_Renderer* renderer = SDL_CreateRenderer(win_ptr, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderDrawRect(renderer, &rect);
	roundedBoxColor(renderer, 50, 50, 500, 400, 7, 0xffffffff);
	SDL_RenderPresent(renderer);

	Dune::Wait(5000);

	SDL_DestroyRenderer(renderer);
	
	return 0;
}
