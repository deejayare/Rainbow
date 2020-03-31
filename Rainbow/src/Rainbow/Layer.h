#pragma once

#include "Rainbow/Core.h"
#include "Rainbow/Core/Timestep.h"
#include "Rainbow/Events/Event.h"

namespace Rainbow {
	
	class RAINBOW_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		// Name used for debug purposes. We generally don't want to refer to layers by names in Distribution builds
		std::string m_DebugName;

	};




}
