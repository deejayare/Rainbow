#pragma once

#ifdef RAINBOW_PLATFORM_WINDOWS

extern Rainbow::Application* Rainbow::CreateApplication();

int main(int argc, char** argv)
{
	Rainbow::Log::Init();
	RAINBOW_CORE_WARN("Initialized Log!");
	int a = 5;
	RAINBOW_INFO("Hello! Var={0}", a);
	auto app = Rainbow::CreateApplication();
	app->Run();
	delete app;
}
#endif