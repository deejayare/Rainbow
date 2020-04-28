#include "rbpch.h"
#include "Rainbow/Core/Window.h"

#ifdef RAINBOW_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Rainbow
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef RAINBOW_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		RAINBOW_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}