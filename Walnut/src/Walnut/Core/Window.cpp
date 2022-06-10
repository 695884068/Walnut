#include "wnpch.h"
#include "Walnut/Core/Window.h"

#ifdef WN_PLATFORM_WINDOWS
	#include "Plateform/Windows/WindowsWindow.h"
#endif

namespace Walnut
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef WN_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		WN_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}