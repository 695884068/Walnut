#include <Walnut.h>


class ExampleLayer : public Walnut::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		WN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Walnut::Event& event) override
	{
		WN_TRACE("{0}", event);
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