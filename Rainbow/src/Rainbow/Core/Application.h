#pragma once

#include "Rainbow/Core/Core.h"
#include "Rainbow/Core/Window.h"
#include "Rainbow/Events/Event.h"
#include "Rainbow/Events/ApplicationEvent.h"
#include "Rainbow/Core/LayerStack.h"
#include "Rainbow/Core/Timestep.h"

#include "Rainbow/Imgui/ImGuiLayer.h"

// TEMPORARY
#include "Rainbow/Renderer/Shader.h"
#include "Rainbow/Renderer/Buffer.h"
#include "Rainbow/Renderer/Vertexarray.h"
#include "Rainbow/Renderer/OrthographicCamera.h"

int main(int argc, char** argv);
namespace Rainbow {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;


		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	//To be defined in CLIENT
	Application* CreateApplication();



}