#pragma once


#ifdef WN_PLATFORM_WINDOWS

extern Walnut::Application* Walnut::CreateApplication();

int main(int args, char** argv)
{
	Walnut::Log::Init();
	WN_CORE_WARN("Initialized Log!");
	int a = 5;
	WN_INFO("HELLO Var=[0]", a);

	auto app = Walnut::CreateApplication();
	app->Run();
	delete app;
}

#endif // WN_PLATFORM_WINDOWS
