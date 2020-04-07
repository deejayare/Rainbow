workspace "Rainbow"
	startproject "Sandbox"
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
	IncludeDir["glad"] = "Rainbow/vendor/glad/include"
	IncludeDir["ImGui"] = "Rainbow/vendor/imgui"
	IncludeDir["glm"] = "Rainbow/vendor/glm"
	IncludeDir["stb_image"] = "Rainbow/vendor/stb_image"
	
	group "Dependencies"
		include "Rainbow/vendor/GLFW"
		include "Rainbow/vendor/glad"
		include "Rainbow/vendor/imgui"
	
	group ""





	project "Rainbow"
		location "Rainbow"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		
		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "rbpch.h"
		pchsource "Rainbow/src/rbpch.cpp"
				
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/glm/glm/**.hpp",
			"%{prj.name}/vendor/glm/glm/**.inl",
			"%{prj.name}/vendor/stb_image/**.h",
			"%{prj.name}/vendor/stb_image/**.cpp"
		}

		defines
		{
			"_CRT_SECURE_NO_WARNINGS"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.glad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}",
			"%{IncludeDir.stb_image}"
		}
		
		links 
		{ 
			"GLFW",
			"glad",
			"ImGui",
			"opengl32.lib"
		}
	

		filter "system:windows"
			systemversion "latest"
			
			defines
			{
				"RAINBOW_PLATFORM_WINDOWS",
				"RAINBOW_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
			}

		filter "configurations:Debug"
			defines "RAINBOW_DEBUG"
			runtime "Debug"
			symbols "on"
		
		filter "configurations:Release"
			defines "RAINBOW_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "RAINBOW_DIST"
			runtime "Release"
			optimize "on"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		
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
			"Rainbow/src",
			"Rainbow/vendor",
			"%{IncludeDir.glm}"
		}

		links
		{
			"Rainbow"
		}

		filter "system:windows"
			systemversion "latest"
			
			defines
			{
				"RAINBOW_PLATFORM_WINDOWS",
			}

		filter "configurations:Debug"
			defines "RAINBOW_DEBUG"
			symbols "on"
			runtime "Debug"
		
		filter "configurations:Release"
			defines "RAINBOW_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "RAINBOW_DIST"
			runtime "Release"
			optimize "on"
