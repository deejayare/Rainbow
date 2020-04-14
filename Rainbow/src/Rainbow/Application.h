#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Rainbow/Events/ApplicationEvent.h"
#include "Rainbow/LayerStack.h"

#include "Rainbow/Imgui/ImGuiLayer.h"

// TEMPORARY
#include "Rainbow/Renderer/Shader.h"

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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;

		static Application* s_Instance;
	};

	//To be definedin CLIENT
	Application* CreateApplication();



}