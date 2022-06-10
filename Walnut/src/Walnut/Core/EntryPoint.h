#pragma once
#include "Walnut/Core/Base.h"
#include "Walnut/Core/Application.h"

#ifdef WN_PLATFORM_WINDOWS

extern Walnut::Application* Walnut::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Walnut::Log::Init();

	WN_PROFILE_BEGIN_SESSION("Startup", "WalnutProfile-Startup.json");
	auto app = Walnut::CreateApplication({ argc, argv });
	WN_PROFILE_END_SESSION();

	WN_PROFILE_BEGIN_SESSION("Runtime", "WalnutProfile-Runtime.json");
	app->Run();
	WN_PROFILE_END_SESSION();

	WN_PROFILE_BEGIN_SESSION("Shutdown", "WalnutProfile-Shutdown.json");
	delete app;
	WN_PROFILE_END_SESSION();
}

#endif
