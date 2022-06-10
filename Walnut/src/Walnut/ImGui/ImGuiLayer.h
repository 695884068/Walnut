#pragma once

#include "Walnut/Core/Layer.h"

#include "Walnut/Events/ApplicationEvent.h"
#include "Walnut/Events/KeyEvent.h"
#include "Walnut/Events/MouseEvent.h"

namespace Walnut {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		ImGuiLayer(const std::string& name);
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		virtual void Begin() {};
		virtual void End() {};
		virtual void OnImGuiRender() {}

		static ImGuiLayer* Create();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}
