#pragma once

#include "core.h"
#include "events/event.h"

namespace xten {

	class XTEN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return _debugName; }

	protected:
		std::string _debugName;
	};

}
