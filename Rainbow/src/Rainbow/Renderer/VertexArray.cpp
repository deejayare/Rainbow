#include "rbpch.h"
#include "Rainbow/Renderer/VertexArray.h"
#include "Rainbow/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Rainbow {
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			RAINBOW_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::API::OpenGL: 
			return CreateRef<OpenGLVertexArray>();
		}

		RAINBOW_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}