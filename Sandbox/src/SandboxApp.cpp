#include <Rainbow.h>
#include <Rainbow/Core/EntryPoint.h>
#include "Platform/OpenGL/OpenGLShader.h"

#include "Rainbow/Renderer/Shader.h"

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Rainbow::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{


	}



};

Rainbow::Application* Rainbow::CreateApplication()
{
	return new Sandbox();
}