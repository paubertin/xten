#include "xtpch.h"
#include "winWindow.h"

namespace xten {

	static bool GLFWInitialized = false;

	Window* Window::create(const WindowProps& props) {
		return new WinWindow(props);
	}

	WinWindow::WinWindow(const WindowProps& props) {
		init(props);
	}

	WinWindow::~WinWindow() {
		shutdown();
	}

	void WinWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WinWindow::setVSync(bool enabled) {
		glfwSwapInterval(enabled ? 1 : 0);
		_data.vSync = enabled;
	}

	bool WinWindow::isVSync() const {
		return _data.vSync;
	}

	void WinWindow::init(const WindowProps& props) {
		_data.title = props.title;
		_data.width = props.width;
		_data.height = props.height;

		XT_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!GLFWInitialized) {
			// TODO: glfwTerminate on shutdown
			int success = glfwInit();
			XT_CORE_ASSERT(success, "Could not initialize GLFW!");
			GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)props.width, (int)props.height, _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		setVSync(true);
	}

	void WinWindow::shutdown() {
		glfwDestroyWindow(_window);
	}

}