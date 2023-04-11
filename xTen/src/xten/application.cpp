#include "application.h"
#include "events/event.h"
#include "events/applicationEvent.h"
#include "log.h"

namespace xten {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		WindowResizeEvent evt(1200, 780);
		XT_TRACE(evt);
		while (true);
	}

}