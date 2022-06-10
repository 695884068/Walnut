#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include "Walnut/ImGui/ImGuiLayer.h"

namespace Walnut
{
	class OpenGLImGuiLayer : public ImGuiLayer
	{
	public:
		OpenGLImGuiLayer() = default;
		OpenGLImGuiLayer(const std::string& name) : ImGuiLayer(name) {}
		virtual ~OpenGLImGuiLayer();

		virtual void Begin() override;
		virtual void End() override;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

	private:
		float m_Time = 0.0f;

	};
}