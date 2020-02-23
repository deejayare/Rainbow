#include <Rainbow.h>

#include "imgui/imgui.h"


class ExampleLayer : public Rainbow::Layer
{
public:
	ExampleLayer() : Layer("Example") 
	{

	}

	void OnUpdate() override 
	{
		//RAINBOW_INFO("ExampleLayer::Update"); 
		if (Rainbow::Input::IsKeyPressed(RAINBOW_KEY_TAB))
			RAINBOW_TRACE("Tab key is pressed!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Rainbow::Event& event) override 
	{
		//RAINBOW_TRACE("{0}", event); 
		if (event.GetEventType() == Rainbow::EventType::KeyPressed)
		{
			Rainbow::KeyPressedEvent& e = (Rainbow::KeyPressedEvent&)event;
			RAINBOW_TRACE("{0}", (char)e.GetKeyCode());
		}
	}


};

class Sandbox : public Rainbow::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{


	}



};

Rainbow::Application* Rainbow::CreateApplication()
{
	return new Sandbox();
}