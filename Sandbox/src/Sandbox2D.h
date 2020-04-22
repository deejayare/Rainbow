#pragma once
#include "Rainbow.h"

class Sandbox2D : public Rainbow::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	void OnUpdate(Rainbow::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Rainbow::Event& e) override;

private:
	Rainbow::OrthographicCameraController m_CameraController;


	// TEMPORARY
	Rainbow::Ref<Rainbow::VertexArray> m_SquareVA;
	Rainbow::Ref<Rainbow::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3, 0.8f, 1.0f };

};