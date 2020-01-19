#include "Window.h"

namespace Dune
{
	//!INCOMPLETE: ... Untested
	//!INCOMPLETE: Does get proper window width, height, or position unless going into fullscreen
	Window::Window(std::string title, uint32_t flags)
		:m_title(title)
	{
		m_rectangle.x, m_rectangle.y = DUNE_WINDOW_CENTERED;

		//check if window should be fullscreen
		if (flags &= WindowFlags::Fullscreen)
		{
			//Get display info
			SDL_DisplayMode DM;
			SDL_GetCurrentDisplayMode(0, &DM);

			//Set the correct width and height
			m_rectangle.width = DM.w;
			m_rectangle.height = DM.h;
		}

		m_window = SDL_CreateWindow(m_title.c_str(), 0, 0, m_rectangle.width, 
			m_rectangle.height, flags);
	}

	Window::Window(std::string title, uint32_t width, uint32_t height, 
		uint32_t flags)
		//replace the name, width and height with the local ones
		:m_title(title), m_rectangle(width, height)
	{
		m_rectangle.x, m_rectangle.y = DUNE_WINDOW_CENTERED;

		m_window = SDL_CreateWindow(m_title.c_str(), m_rectangle.x, m_rectangle.y,
			m_rectangle.width, m_rectangle.height, flags);
	}

	Window::Window(std::string title, uint32_t x, uint32_t y, uint32_t width, uint32_t height, 
		uint32_t flags)
		//replace the some of the window data with the local ones
		:m_title(title), m_rectangle(width, height, x, y)
	{
		m_window = SDL_CreateWindow(m_title.c_str(), m_rectangle.x, m_rectangle.y,
			m_rectangle.width, m_rectangle.height, flags);
	}

	Window::Window(SDL_Window* window)
		:m_window(window)
	{
		//get te window title using a member function
		m_title = GetTitle();

	}

	void Window::ShowWindow()
	{
		//If the window is already shown, this shouldn't do anything
		SDL_ShowWindow(m_window);
		DUNE_VA_LOG("The window %s has been shown.", m_title.c_str());
	}

	void Window::HideWindow()
	{
		//If the window is already hidden, this shouldn't do anything
		SDL_HideWindow(m_window);
		DUNE_VA_LOG("The window %s been hidden.", m_title.c_str());
	}

	inline SDL_Window* Window::GetSDL_Window()
	{
		return m_window;
	}

	void Window::SetTitle(std::string title)
	{
		//set the member variable to the new title
		m_title = title;

		//actually change the title of the window
		SDL_SetWindowTitle(m_window, m_title.c_str());
	}

	inline std::string Window::GetTitle()
	{
		return m_title;
	}

	inline Rectangle Window::GetDimensions()
	{
		return m_rectangle;
	}

	void Window::SetFullscreen()
	{
		//Get display info
		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);

		//Set the correct width and height
		m_rectangle.width = uint32_t(DM.w);
		m_rectangle.height = uint32_t(DM.h);

		//Make the window fullscreen
		SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);

		DUNE_VA_LOG("The window %s has been made fullscreen", m_title.c_str());
	}

	void Window::Close()
	{
		SDL_DestroyWindow(m_window);
		DUNE_VA_LOG("Window \"%s\" Closed", m_title.c_str());
	}

	Window::~Window()
	{
		Close();
	}
}
