#pragma once

#include "Rainbow/Core/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Rainbow {


	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define RAINBOW_CORE_TRACE(...)     ::Rainbow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RAINBOW_CORE_INFO(...)      ::Rainbow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RAINBOW_CORE_WARN(...)      ::Rainbow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RAINBOW_CORE_ERROR(...)     ::Rainbow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RAINBOW_CORE_CRITICAL(...)  ::Rainbow::Log::GetCoreLogger()->critical(__VA_ARGS__)



// Core log macros
#define RAINBOW_TRACE(...)    ::Rainbow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RAINBOW_INFO(...)     ::Rainbow::Log::GetClientLogger()->info(__VA_ARGS__)
#define RAINBOW_WARN(...)     ::Rainbow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RAINBOW_ERROR(...)    ::Rainbow::Log::GetClientLogger()->error(__VA_ARGS__)
#define RAINBOW_CRITICAL(...) ::Rainbow::Log::GetClientLogger()->critical(__VA_ARGS__) 

