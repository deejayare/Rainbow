#include "rbpch.h"
#include "Rainbow/Renderer/RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Rainbow {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();


}