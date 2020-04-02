#pragma once

#include "Rainbow/Renderer/RendererAPI.h"

namespace Rainbow {

	class OpenGLRendererAPI : public RendererAPI
	{

	public:
		virtual void SetClearColor(const glm::vec4& color)  override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) ;

	};


}