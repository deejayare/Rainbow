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
	

	include "Rainbow/vendor/GLFW"
	include "Rainbow/vendor/glad"
	include "Rainbow/vendor/imgui"

	



	group "Dependencies"
		include "Rainbow/vendor/GLFW"
		include "Rainbow/vendor/glad"
		include "Rainbow/vendor/imgui"
	
	group ""





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
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/glm/glm/**.hpp",
			"%{prj.name}/vendor/glm/glm/**.inl"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.glad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}"
		}
		
		links 
		{ 
			"GLFW",
			"glad",
			"ImGui",
			"opengl32.lib"
		}
	

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "Off"
			systemversion "latest"
			
			defines
			{
				"RAINBOW_PLATFORM_WINDOWS",
				"RAINBOW_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")

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
			"Rainbow/src",
			"Rainbow/vendor",
			"%{IncludeDir.glm}"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "Off"
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
			optimize "On"
