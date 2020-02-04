#include <Rainbow.h>


class ExampleLayer : public Rainbow::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override { RAINBOW_INFO("ExampleLayer::Update"); }

	void OnEvent(Rainbow::Event& event) override { RAINBOW_TRACE("{0}", event); }


};

class Sandbox : public Rainbow::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Rainbow::ImGuiLayer());

	}

	~Sandbox()
	{


	}



};

Rainbow::Application* Rainbow::CreateApplication()
{
	return new Sandbox();
}