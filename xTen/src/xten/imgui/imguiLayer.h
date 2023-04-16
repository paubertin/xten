#pragma once

#include "xten/layer.h"
#include <xten/events/applicationEvent.h>
#include <xten/events/mouseEvent.h>
#include <xten/events/keyEvent.h>

namespace xten {

	class XTEN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);

	private:
		bool onMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool onMouseMovedEvent(MouseMovedEvent& e);
		bool onMouseScrolledEvent(MouseScrolledEvent& e);
		bool onWindowResizeEvent(WindowResizeEvent& e);
		bool onKeyTypedEvent(KeyTypedEvent& e);
		bool onKeyPressedEvent(KeyPressedEvent& e);
		bool onKeyReleasedEvent(KeyReleasedEvent& e);

	private:
		float _time = 0.0f;
	};

}