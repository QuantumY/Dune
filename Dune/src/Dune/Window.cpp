#include "Window.h"

namespace Dune
{
	Window::Window(std::string title, uint32_t width, uint32_t height)
		:m_props({ title, DUNE_WINDOW_CENTERED_XY, width, height })
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, WindowFlags::Default);
	}
	
	Window::Window(std::string title, uint32_t width, uint32_t height, uint32_t flags)
		:m_props({ title, DUNE_WINDOW_CENTERED_XY, width, height })
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, flags);
	}

	Window::Window(std::string title, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		: m_props({ title, x, y, width, height })
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, WindowFlags::Default);
	}

	Window::Window(std::string title, uint32_t x, uint32_t y, uint32_t width, uint32_t height, 
		uint32_t flags)
		: m_props({ title, x, y, width, height })
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, flags);
	}

	Window::Window(WindowProps props)
		:m_props(props)
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, WindowFlags::Default);
	}

	Window::Window(WindowProps props, uint32_t flags)
		:m_props(props)
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, flags);
	}

	WindowProps Window::GetWindowProps()
	{
		return m_props;
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_window);
	}
}
