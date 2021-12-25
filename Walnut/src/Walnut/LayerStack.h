#pragma once

#include "Walnut/Core.h"
#include "Layer.h"

#include <vector>

namespace Walnut {
	
	class WALNUT_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layer.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layer.end(); }
	private:
		std::vector<Layer*> m_Layer;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}