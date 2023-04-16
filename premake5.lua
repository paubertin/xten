workspace "xTen"
	architecture "x64"

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

include "xTen/vendor/GLFW"
include "xTen/vendor/Glad"

project "xTen"
	location "xTen"
	kind "SharedLib"
	language "C++"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "xtpch.h"
	pchsource "xTen/src/xtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"XT_PLATFORM_WINDOWS",
			"XT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:debug"
		defines "XT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:release"
		defines "XT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:dist"
		defines "XT_DIST"
		buildoptions "/MD"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"xTen/src"
	}

	links
	{
		"xTen"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"XT_PLATFORM_WINDOWS"
		}

	filter "configurations:debug"
		defines "XT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:release"
		defines "XT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:dist"
		defines "XT_DIST"
		buildoptions "/MD"
		optimize "On"