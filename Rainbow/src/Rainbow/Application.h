#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Rainbow/Events/ApplicationEvent.h"
#include "Rainbow/LayerStack.h"

namespace Rainbow {

	class RAINBOW_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be definedin CLIENT
	Application* CreateApplication();



}