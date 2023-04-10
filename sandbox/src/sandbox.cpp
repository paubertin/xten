#include <xten.h>

class Sandbox : public xten::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

xten::Application* xten::createApplication()
{
	return new Sandbox();
}