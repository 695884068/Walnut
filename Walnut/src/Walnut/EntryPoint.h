#pragma once


#ifdef WN_PLATFORM_WINDOWS

extern Walnut::Application* Walnut::CreateApplication();

int main(int args, char** argv)
{
	auto app = Walnut::CreateApplication();
	app->Run();
	delete app;
}

#endif // WN_PLATFORM_WINDOWS
