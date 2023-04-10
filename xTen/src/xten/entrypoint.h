#pragma once

#include "application.h"

#ifdef XT_PLATFORM_WINDOWS

extern xten::Application* xten::createApplication();

int main(int argc, char** argv)
{
	auto app = xten::createApplication();
	app->run();
	delete app;
}

#endif // XT_PLATFORM_WINDOWS
