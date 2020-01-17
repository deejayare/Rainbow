#include <Rainbow.h>

class Sandbox : public Rainbow::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{


	}



};

Rainbow::Application* Rainbow::CreateApplication()
{
	return new Sandbox();
}