#pragma once

#include "Walnut/Core/Base.h"
		  
#include "Walnut/Core/Window.h"
#include "Walnut/Core/LayerStack.h"
#include "Walnut/Events/Event.h"
#include "Walnut/Events/ApplicationEvent.h"
		  
#include "Walnut/Core/Timestep.h"
		  
#include "Walnut/ImGui/ImGuiLayer.h"

#include "Walnut/Asset/PublicSingleton.h"

int main(int argc, char** argv);

namespace Walnut {

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			WN_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	class Application : public PublicSingleton<Application>
	{
	public:
		Application(const std::string& name = "Hazel App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		ApplicationCommandLineArgs m_CommandLineArgs;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);

}
