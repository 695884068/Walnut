#pragma once

#include "Core.h"
#include "Window.h"
#include "Walnut/LayerStack.h"
#include "Walnut/Events/Event.h"
#include "Walnut/Events/ApplicationEvent.h"
#include "Walnut/ImGui/ImGuiLayer.h"

#include "Walnut/Renderer/Shader.h"
#include "Walnut/Renderer/Buffer.h"
#include "Walnut/Renderer/VertexArray.h"

#include "Walnut/Renderer/OrthographicCamera.h"

namespace Walnut {

	class WALNUT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}
