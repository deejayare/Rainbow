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

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

		static Application* s_Instance;
	};

	//To be definedin CLIENT
	Application* CreateApplication();



}