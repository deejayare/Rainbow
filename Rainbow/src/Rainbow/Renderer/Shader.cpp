#include "rbpch.h"
#include "Shader.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Rainbow {
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			RAINBOW_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		RAINBOW_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}