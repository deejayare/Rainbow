#pragma once

#include "Rainbow.h"

class ExampleLayer : public Rainbow::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Rainbow::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Rainbow::Event& e) override;
private:

	Rainbow::ShaderLibrary m_ShaderLibrary;
	Rainbow::Ref<Rainbow::Shader> m_Shader;
	Rainbow::Ref<Rainbow::VertexArray> m_VertexArray;

	Rainbow::Ref<Rainbow::Shader> m_FlatColorShader;
	Rainbow::Ref<Rainbow::VertexArray> m_SquareVA;

	Rainbow::Ref<Rainbow::Texture2D> m_Texture, m_HeartTexture;

	Rainbow::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3, 0.8f };
};

#pragma once
