#include "xtpch.h"
#include "winWindow.h"

#include "xten/events/applicationEvent.h"
#include "xten/events/keyEvent.h"
#include "xten/events/mouseEvent.h"

namespace xten {

	static bool GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		XT_CORE_ERROR("GLFW error (${0}): ${1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)props.width, (int)props.height, _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		setVSync(true);

		// set GLFW callbacks
		setEventCallbacks();
	}

	void WinWindow::shutdown() {
		glfwDestroyWindow(_window);
	}

	void WinWindow::setEventCallbacks() {
		glfwSetWindowSizeCallback(
			_window,
			[](GLFWwindow* window, int width, int height) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;
				WindowResizeEvent event(width, height);
				data.eventCallback(event);
			});

		glfwSetWindowCloseCallback(
			_window,
			[](GLFWwindow* window) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.eventCallback(event);
			});

		glfwSetKeyCallback(
			_window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
				case GLFW_PRESS: {
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(
			_window,
			[](GLFWwindow* window, int button, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(
			_window,
			[](GLFWwindow* window, double xOffset, double yOffset) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.eventCallback(event);
			});

		glfwSetCursorPosCallback(
			_window,
			[](GLFWwindow* window, double xPos, double yPos) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)xPos, (float)yPos);
				data.eventCallback(event);
			});
	}

}