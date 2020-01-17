#pragma once

#include "Core.h"

namespace Rainbow {

	class RAINBOW_API Application
	{
		public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be definedin CLIENT
	Application* CreateApplication();



}