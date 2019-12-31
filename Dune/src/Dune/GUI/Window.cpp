#include "Window.h"

namespace Dune
{
	//!INCOMPLETE: Does get proper window width, height, or position unless going into fullscreen
	Window::Window(std::string title, uint32_t flags)
		:m_props({ title, 0, 0, 0, 0 })
	{

		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, flags);

		//check if window should be fullscreen
		if (flags &= WindowFlags::Fullscreen)
			//This is the method that makes the window fullscreen
			MakeWindowFullscreen();
	}

	Window::Window(std::string title, uint32_t width, uint32_t height, 
		uint32_t flags)
		:m_props({ title, DUNE_WINDOW_CENTERED, DUNE_WINDOW_CENTERED, width, height })
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, flags);
	}

	Window::Window(std::string title, uint32_t x, uint32_t y, uint32_t width, uint32_t height, 
		uint32_t flags)
		: m_props({ title, x, y, width, height })
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, flags);
	}

	Window::Window(WindowProps props, uint32_t flags)
		:m_props(props)
	{
		m_window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y,
			m_props.width, m_props.height, flags);
	}

	void Window::ShowWindow()
	{
		//If the window is already shown, this shouldn't do anything
		SDL_ShowWindow(m_window);
		DUNE_BASIC_LOG("The window has been shown.");
	}

	void Window::HideWindow()
	{
		//If the window is already hidden, this shouldn't do anything
		SDL_HideWindow(m_window);
		DUNE_BASIC_LOG("The window has been hidden.");
	}

	WindowProps Window::GetWindowProps()
	{
		return m_props;
	}

	SDL_Window* Window::GetSDL_Window()
	{
		return m_window;
	}

	void Window::MakeWindowFullscreen()
	{
		//Get display info
		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);

		//Set the correct width and height
		m_props.width = uint32_t(DM.w);
		m_props.height = uint32_t(DM.h);

		//Make the window fullscreen
		SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_window);
	}
}
