#pragma once

#include "Rainbow/Core/Layer.h"

#include "Rainbow/Events/ApplicationEvent.h"
#include "Rainbow/Events/MouseEvent.h"
#include "Rainbow/Events/KeyEvent.h"

namespace Rainbow {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;


		virtual void OnDetach() override;
		virtual void OnAttach() override;
		virtual void OnImGuiRender() override;
		
		void Begin();
		void End();
			   
	private:
		float m_Time = 0.0f;


	};

}