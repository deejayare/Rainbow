#include "SandBox2D.h"
#include "imgui/imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Platform/OpenGL/OpenGLShader.h"


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(16.0f / 9.0f, true)
{

}


void Sandbox2D::OnAttach()
{



}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Rainbow::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);


	// Render
	Rainbow::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Rainbow::RenderCommand::Clear();


	Rainbow::Renderer2D::BeginScene(m_CameraController.GetCamera());
	   
	Rainbow::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });

	Rainbow::Renderer2D::EndScene();

	// TODO: add Shader::SetMat4, etc in place of dynamic cast
	//std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_FlatColorShader)->Bind();
	//std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Color Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Rainbow::Event& e)
{
	m_CameraController.OnEvent(e);
}
