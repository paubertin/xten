#pragma once

#include "xten/window.h"

#include <GLFW/glfw3.h>

namespace xten {

	class WinWindow : public Window
	{
	public:
		WinWindow(const WindowProps& props);
		virtual ~WinWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return _data.width; }
		inline unsigned int getHeight() const override { return _data.height; }

		// window attributes
		inline void setEventCallback(const EventCallbackFn& cb) override { _data.eventCallback = cb; }
		void setVSync(bool enabled);
		bool isVSync() const;

		inline virtual void* getNativeWindow() const { return _window; }

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

	private:
		GLFWwindow* _window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData _data;

		void setEventCallbacks();

	};

}