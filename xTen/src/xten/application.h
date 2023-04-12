#pragma once

#include "core.h"
#include "window.h"

namespace xten {

	class XTEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// to be defined in client
	Application* createApplication();
}

