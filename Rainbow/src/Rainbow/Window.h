#pragma once

#include "rbpch.h"

#include "Rainbow/Core.h"
#include "Rainbow/Events/Event.h"

namespace Rainbow {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		// Default Window properties
		WindowProps(const std::string& title = "Rainbow Engine", 
					unsigned int width = 1920, 
					unsigned int height = 1080) 
			: Title(title), Width(width), Height(height) 
		{
		}
	};

	// Interface representing a PC based Window
	class RAINBOW_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)> ;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// Create should return a window based on which platform we're on (Windows/Linux/Mac)
		static Window* Create(const WindowProps& props = WindowProps());
	};


}