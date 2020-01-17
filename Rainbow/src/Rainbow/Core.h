#pragma once

#ifdef RAINBOW_PLATFORM_WINDOWS
	#ifdef RAINBOW_BUILD_DLL
		#define RAINBOW_API __declspec(dllexport)
	#else
		#define RAINBOW_API __declspec(dllimport)
	#endif // RB_BUILD_DLL
#else
	#error Rainbow only supports Windows!
#endif //RB_PLATFORM_WINDOWS
