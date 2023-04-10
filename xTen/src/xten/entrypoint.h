#pragma once

#ifdef XT_PLATFORM_WINDOWS

extern xten::Application* xten::createApplication();

int main(int argc, char** argv)
{
	xten::Log::init();
	XT_CORE_WARN("Initialized log");
	int a = 5;
	XT_INFO("Hello! Var={0}", a);

	auto app = xten::createApplication();
	app->run();
	delete app;
}

#endif // XT_PLATFORM_WINDOWS
