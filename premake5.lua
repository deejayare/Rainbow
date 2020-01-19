workspace "Rainbow"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "Rainbow"
		location "Rainbow"
		kind "SharedLib"
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
			"%{prj.name}/vendor/spdlog/include"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "10.0.18362.0"
			
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
			systemversion "10.0.18362.0"
			
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
