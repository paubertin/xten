workspace "xTen"
	architecture "x64"

	startproject "sandbox"

	configurations
	{
		"debug",
		"release",
		"dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "xTen/vendor/GLFW/include"
IncludeDir["Glad"] = "xTen/vendor/Glad/include"
IncludeDir["ImGui"] = "xTen/vendor/imgui"
IncludeDir["glm"] = "xTen/vendor/glm"

group "dependencies"
	include "xTen/vendor/GLFW"
	include "xTen/vendor/Glad"
	include "xTen/vendor/imgui"

group ""

project "xTen"
	location "xTen"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "xtpch.h"
	pchsource "xTen/src/xtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
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
			"XT_PLATFORM_WINDOWS",
			"XT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/sandbox/\"")
		}

	filter "configurations:debug"
		defines "XT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:release"
		defines "XT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:dist"
		defines "XT_DIST"
		runtime "Release"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"xTen/vendor/spdlog/include",
		"xTen/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"xTen"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"XT_PLATFORM_WINDOWS"
		}

	filter "configurations:debug"
		defines "XT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:release"
		defines "XT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:dist"
		defines "XT_DIST"
		runtime "Release"
		optimize "On"
