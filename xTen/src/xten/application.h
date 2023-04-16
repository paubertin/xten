#pragma once

#include "core.h"
#include "window.h"
#include "events/applicationEvent.h"
#include "layerstack.h"

namespace xten {

	class XTEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);
	private:
		bool onWindowClose(WindowCloseEvent& evt);
		std::unique_ptr<Window> _window;
		bool _running = true;
		LayerStack _layerStack;
	};

	// to be defined in client
	Application* createApplication();
}

