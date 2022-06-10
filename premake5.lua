workspace "Walnut"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to toor folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Walnut/vendor/GlFW/include"
IncludeDir["Glad"] = "Walnut/vendor/Glad/include"
IncludeDir["ImGui"] = "Walnut/vendor/imgui"
IncludeDir["ImGuizmo"] = "Walnut/vendor/ImGuizmo"
IncludeDir["glm"] = "Walnut/vendor/glm"
IncludeDir["stb_image"] = "Walnut/vendor/stb_image"
IncludeDir["assimp"] = "Walnut/vendor/assimp/include"
IncludeDir["SPIRV-Cross"] = "Walnut/vendor/SPIRV-Cross"
IncludeDir["shaderc"] = "Walnut/vendor/shaderc/libshaderc/include"
IncludeDir["entt"] = "Walnut/vendor/entt/include"
IncludeDir["yaml_cpp"] = "Walnut/vendor/yaml-cpp/include"

group "Dependencies"
	include "Walnut/vendor/GLFW"
	include "Walnut/vendor/Glad"
	include "Walnut/vendor/imgui"
	include "Walnut/vendor/yaml-cpp"
group ""

project "Walnut"
	location "Walnut"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
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
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/ImGuizmo/ImGuizmo.h",
		"%{prj.name}/vendor/ImGuizmo/ImGuizmo.cpp"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{prj.name}/vendor/SPIRV-Cross;",
		"%{prj.name}/vendor/shaderc/libshaderc/include;",
		"%{prj.name}/vendor/bullet3/src;",
		"%{prj.name}/vendor/FMOD;",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.ImGuizmo}",
		"%{IncludeDir.assimp}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib",
		"bullet3"
	}
	filter "files:vendor/ImGuizmo/**.cpp"
	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"WN_PLATFORM_WINDOWS",
			"WN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "WN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "WN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "WN_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}",
		"src"
	}

	links
	{
		"Walnut"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"WN_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "WN_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "WN_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "WN_DIST"
			runtime "Release"
			optimize "on"