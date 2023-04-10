#pragma once

#include "core.h"

namespace xten {

	class XTEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// to be defined in client
	Application* createApplication();
}

