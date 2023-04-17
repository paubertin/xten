#include "xtpch.h"
#include "winInput.h"

#include <xten/application.h>
#include <GLFW/glfw3.h>

namespace xten {

	Input* Input::_instance = new WinInput();

	bool WinInput::isKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WinInput::isMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WinInput::getMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float WinInput::getMouseXImpl()
	{
		auto [x, y] = getMousePositionImpl();
		return x;
	}

	float WinInput::getMouseYImpl()
	{
		auto [x, y] = getMousePositionImpl();
		return y;
	}

}