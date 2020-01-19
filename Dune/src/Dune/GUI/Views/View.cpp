#include "View.h"

namespace Dune
{
	void View::Destroy()
	{
		SDL_DestroyRenderer(m_renderer);
		DUNE_VA_LOG("%s destroyed", m_title.c_str());
	}
}
