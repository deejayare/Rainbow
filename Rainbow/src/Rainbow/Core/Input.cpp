#include "rbpch.h"
#include "Rainbow/Core/Input.h"

#ifdef RAINBOW_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Rainbow {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef RAINBOW_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		RAINBOW_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}