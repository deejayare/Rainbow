#pragma once

#ifdef RAINBOW_PLATFORM_WINDOWS
	#if RAINBOW_DYNAMIC_LINK
		#ifdef RAINBOW_BUILD_DLL
			#define RAINBOW_API __declspec(dllexport)
		#else
			#define RAINBOW_API __declspec(dllimport)
		#endif // RB_BUILD_DLL
	#else
		#define RAINBOW_API //static linking - this prevents __declspec(dllimport). Ideally we probably want to just remove RAINBOW_API in from all of our classes if we want static linking.
	#endif
#else
	#error Rainbow only supports Windows!
#endif //RB_PLATFORM_WINDOWS


#ifdef RAINBOW_DEBUG
	#define RAINBOW_ENABLE_ASSERTS
#endif

#ifdef RAINBOW_ENABLE_ASSERTS
	#define RAINBOW_ASSERT(x, ...) { if(!(x)) { RAINBOW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RAINBOW_CORE_ASSERT(x, ...) { if(!(x)) { RAINBOW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RAINBOW_ASSERT(x, ...)
	#define RAINBOW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RAINBOW_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)