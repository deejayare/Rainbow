#include "rbpch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Rainbow {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;



}