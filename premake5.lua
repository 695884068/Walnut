workspace "Walnut"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to toor folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Walnut/vendor/GlFW/include"
IncludeDir["Glad"] = "Walnut/vendor/Glad/include"
IncludeDir["ImGui"] = "Walnut/vendor/imgui"
IncludeDir["glm"] = "Walnut/vendor/glm"

include "Walnut/vendor/GLFW"
include "Walnut/vendor/Glad"
include "Walnut/vendor/imgui"

project "Walnut"
	location "Walnut"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "wnpch.h"
	pchsource "Walnut/src/wnpch.cpp" 

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"WN_PLATFORM_WINDOWS",
			"WN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

		filter "configurations:Debug"
			defines "WN_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "WN_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "WN_DIST"
			runtime "Release"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Walnut/vendor/spdlog/include;",
		"Walnut/src",
		"Walnut/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Walnut"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"WN_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "WN_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "WN_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "WN_DIST"
			runtime "Release"
			optimize "On"