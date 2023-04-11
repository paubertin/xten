workspace "xTen"
	architecture "x64"

	configurations
	{
		"debug",
		"release",
		"dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "xTen"
	location "xTen"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"XT_PLATFORM_WINDOWS",
			"XT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:debug"
		defines "XT_DEBUG"
		symbols "On"

	filter "configurations:release"
		defines "XT_RELEASE"
		optimize "On"

	filter "configurations:dist"
		defines "XT_DIST"
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
		symbols "On"

	filter "configurations:release"
		defines "XT_RELEASE"
		optimize "On"

	filter "configurations:dist"
		defines "XT_DIST"
		optimize "On"