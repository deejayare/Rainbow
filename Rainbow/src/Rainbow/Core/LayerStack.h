#pragma once

#include "Rainbow/Core/Core.h"
#include "Rainbow/Core/Layer.h"

#include <vector>

namespace Rainbow {

	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		// We want layers in the first section of the stack, and overlays in the second section of the stack. LayerInsert is the dividing point.
		unsigned int  m_LayerInsertIndex = 0;



	};


}