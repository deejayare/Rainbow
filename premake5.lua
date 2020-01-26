workspace "Rainbow"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Rainbow/vendor/GLFW/include"

	include "Rainbow/vendor/GLFW"

	project "Rainbow"
		location "Rainbow"
		kind "SharedLib"
		language "C++"
		
		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "rbpch.h"
		pchsource "Rainbow/src/rbpch.cpp"
				
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}"
		}
		
		links 
		{ 
			"GLFW",
			"opengl32.lib"
		}
	

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
			
			defines
			{
				"RAINBOW_PLATFORM_WINDOWS",
				"RAINBOW_BUILD_DLL"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")

			}

		filter "configurations:Debug"
			defines "RAINBOW_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "RAINBOW_RELEASE"
			symbols "On"

		filter "configurations:Dist"
			defines "RAINBOW_DIST"
			symbols "On"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"

		language "C++"
		
		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"Rainbow/vendor/spdlog/include",
			"Rainbow/src"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
			
			defines
			{
				"RAINBOW_PLATFORM_WINDOWS",
			}

			links
			{
				"Rainbow"
			}

		filter "configurations:Debug"
			defines "RAINBOW_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "RAINBOW_RELEASE"
			symbols "On"

		filter "configurations:Dist"
			defines "RAINBOW_DIST"
			symbols "On"
