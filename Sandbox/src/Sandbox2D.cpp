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
	
	// Particle Init
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 1.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };
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
	Rainbow::Renderer2D::ResetStats();
	{
		RAINBOW_PROFILE_SCOPE("Renderer Prep");
		Rainbow::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Rainbow::RenderCommand::Clear();
	}
	
	{
		RAINBOW_PROFILE_SCOPE("Renderer Draw");
		static float rotation = 0.0f;
		rotation += ts * 20.0f;

		Rainbow::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Rainbow::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(4*rotation) , { 0.8f, 0.2f, 0.3f, 1.0f });
		Rainbow::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Rainbow::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Rainbow::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Rainbow::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(-rotation), m_CheckerboardTexture, 20.0f);
		Rainbow::Renderer2D::EndScene();


		Rainbow::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.8f };
				//Rainbow::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
				Rainbow::Renderer2D::DrawRotatedQuad({ x, y }, { 0.45f, 0.45f }, glm::radians(rotation * ( 1 - (y + 5.0f) / 10.0f ) ), color);
			}
		}

		Rainbow::Renderer2D::EndScene();



		if (Rainbow::Input::IsMouseButtonPressed(RAINBOW_MOUSE_BUTTON_LEFT))
		{
			auto [x, y] = Rainbow::Input::GetMousePosition();
			auto width = Rainbow::Application::Get().GetWindow().GetWidth();
			auto height = Rainbow::Application::Get().GetWindow().GetHeight();

			auto bounds = m_CameraController.GetBounds();
			auto pos = m_CameraController.GetCamera().GetPosition();
			x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
			y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
			m_Particle.Position = { x + pos.x, y + pos.y };
			for (int i = 0; i < 50; i++)
				m_ParticleSystem.Emit(m_Particle);
		}

		m_ParticleSystem.OnUpdate(ts);
		m_ParticleSystem.OnRender(m_CameraController.GetCamera());



	}

}

void Sandbox2D::OnImGuiRender()
{
	RAINBOW_PROFILE_FUNCTION();
	ImGui::Begin("Color Settings");


	auto stats = Rainbow::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indicies: %d", stats.GetTotalIndexCount());


	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Rainbow::Event& e)
{
	m_CameraController.OnEvent(e);
}
