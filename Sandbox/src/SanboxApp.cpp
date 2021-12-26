#include <Walnut.h>

#include "Walnut/Input.h"

class ExampleLayer : public Walnut::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Walnut::Input::IsKeyPressed(WN_KEY_TAB))
			WN_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Walnut::Event& event) override
	{
		if (event.GetEventType() == Walnut::EventType::KeyPressed)
		{
			Walnut::KeyPressedEvent& e = (Walnut::KeyPressedEvent&)event;
			if (e.GetKeyCode() == WN_KEY_TAB)
				WN_TRACE("Tab key is pressed (event)!");
			WN_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sanbox : public Walnut::Application
{
public:
	Sanbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Walnut::ImGuiLayer());
	}

	~Sanbox()
	{
	}
};

Walnut::Application* Walnut::CreateApplication()
{
	return new Sanbox();
}