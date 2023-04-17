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
		if (xten::Input::isKeyPressed(XT_KEY_A))
			XT_TRACE("'A' key is pressed");
	}

	void onEvent(xten::Event& evt) override
	{
		if (evt.getEventType() == xten::EventType::KeyPressed) {
			xten::KeyPressedEvent& e = (xten::KeyPressedEvent&)evt;
;			XT_TRACE("{0}", (char)e.getKeyCode());

		}
	}
};

class Sandbox : public xten::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new xten::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

xten::Application* xten::createApplication()
{
	return new Sandbox();
}