#include <xten.h>

class ExampleLayer : public xten::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void onUpdate() override
	{
		XT_INFO("ExampleLayer::update");
	}

	void onEvent(xten::Event& evt) override
	{
		XT_TRACE("{0}", evt);
	}
};

class Sandbox : public xten::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

xten::Application* xten::createApplication()
{
	return new Sandbox();
}