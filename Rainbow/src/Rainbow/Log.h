#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rainbow {


	class RAINBOW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr <spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define RAINBOW_CORE_TRACE(...)  ::Rainbow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RAINBOW_CORE_INFO(...)   ::Rainbow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RAINBOW_CORE_WARN(...)   ::Rainbow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RAINBOW_CORE_ERROR(...)  ::Rainbow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RAINBOW_CORE_FATAL(...)  ::Rainbow::Log::GetCoreLogger()->fatal(__VA_ARGS__)



// Core log macros
#define RAINBOW_TRACE(...)  ::Rainbow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RAINBOW_INFO(...)   ::Rainbow::Log::GetClientLogger()->info(__VA_ARGS__)
#define RAINBOW_WARN(...)   ::Rainbow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RAINBOW_ERROR(...)  ::Rainbow::Log::GetClientLogger()->error(__VA_ARGS__)
#define RAINBOW_FATAL(...)  ::Rainbow::Log::GetClientLogger()->fatal(__VA_ARGS__)

