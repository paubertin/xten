#include "xtpch.h"
#include "application.h"
#include "events/applicationEvent.h"
#include <GLFW/glfw3.h>

namespace xten {

	Application::Application()
	{
		_window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->onUpdate();
		}
	}

}