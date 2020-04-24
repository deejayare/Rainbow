#include "rbpch.h"
#include "Rainbow/Renderer/Texture.h"
#include "Rainbow/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Rainbow {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			RAINBOW_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::API::OpenGL: 
			return CreateRef<OpenGLTexture2D>(width, height);
		}

		RAINBOW_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			RAINBOW_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::API::OpenGL: 
			return CreateRef<OpenGLTexture2D>(path);
		}

		RAINBOW_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}