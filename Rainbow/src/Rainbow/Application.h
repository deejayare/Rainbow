#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Rainbow/Events/ApplicationEvent.h"
#include "Rainbow/LayerStack.h"

#include "Rainbow/Imgui/ImGuiLayer.h"

// TEMPORARY
#include "Rainbow/Renderer/Shader.h"
#include "Rainbow/Renderer/Buffer.h"
#include "Rainbow/Renderer/Vertexarray.h"
#include "Rainbow/Renderer/OrthographicCamera.h"

namespace Rainbow {

	class RAINBOW_API Application
	{
	public:
		Application();
		virtual ~Application() = default;
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;


		static Application* s_Instance;
	};

	//To be defined in CLIENT
	Application* CreateApplication();



}