#include "SandBox2D.h"
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(16.0f / 9.0f, true), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{

}


void Sandbox2D::OnAttach()
{
	RAINBOW_PROFILE_FUNCTION();
	m_CheckerboardTexture = Rainbow::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	RAINBOW_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Rainbow::Timestep ts)
{
	RAINBOW_PROFILE_FUNCTION();
	// Update
	m_CameraController.OnUpdate(ts);



	// Render
	{
		RAINBOW_PROFILE_SCOPE("Renderer Prep");
		Rainbow::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Rainbow::RenderCommand::Clear();
	}
	
	{
		RAINBOW_PROFILE_SCOPE("Renderer Draw");
		Rainbow::Renderer2D::BeginScene(m_CameraController.GetCamera());
		//Rainbow::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f) , { 0.8f, 0.2f, 0.3f, 1.0f });
		Rainbow::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Rainbow::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Rainbow::Renderer2D::DrawQuad({ -5.0f, -5.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		Rainbow::Renderer2D::DrawQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f }, m_CheckerboardTexture, 20.0f);
		Rainbow::Renderer2D::EndScene();
	}

}

void Sandbox2D::OnImGuiRender()
{
	RAINBOW_PROFILE_FUNCTION();
	ImGui::Begin("Color Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Rainbow::Event& e)
{
	m_CameraController.OnEvent(e);
}
