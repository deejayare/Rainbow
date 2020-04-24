#pragma once
#include "Rainbow/Core/Core.h"

#ifdef RAINBOW_PLATFORM_WINDOWS

extern Rainbow::Application* Rainbow::CreateApplication();

int main(int argc, char** argv)
{
	Rainbow::Log::Init();

	RAINBOW_PROFILE_BEGIN_SESSION("Startup", "RainbowProfile-Startup.json");
	auto app = Rainbow::CreateApplication();
	RAINBOW_PROFILE_END_SESSION();

	RAINBOW_PROFILE_BEGIN_SESSION("Runtime", "RainbowProfile-Runtime.json");
	app->Run();
	RAINBOW_PROFILE_END_SESSION();

	RAINBOW_PROFILE_BEGIN_SESSION("Shutdown", "RainbowProfile-Shutdown.json");
	delete app;
	RAINBOW_PROFILE_END_SESSION();
}
#endif