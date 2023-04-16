#include "xtpch.h"
#include "application.h"
#include <glad/glad.h>

namespace xten {

	Application* Application::instance = nullptr;

	Application::Application()
	{
		XT_CORE_ASSERT(!instance, "Application already exists.");
		instance = this;
		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : _layerStack) {
				layer->onUpdate();
			}

			_window->onUpdate();
		}
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));

		for (auto it = _layerStack.end(); it != _layerStack.begin(); ) {
			(*--it)->onEvent(e);
			if (e.handled) {
				break;
			}
		}
	}

	void Application::pushLayer(Layer* layer)
	{
		_layerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* layer)
	{
		_layerStack.pushOverlay(layer);
		layer->onAttach();
	}

	bool Application::onWindowClose(WindowCloseEvent& evt)
	{
		_running = false;
		return true;
	}

}