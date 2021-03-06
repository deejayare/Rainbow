#include "SandBox2D.h"
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>

static const uint32_t s_MapWidth = 24;
static const char* s_MapTiles = 
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWDDDDDDWWWWWWWWWW"
"WWWWWWWDDDDDDDWWWWWWWWWW"
"WWWWWWDDDDDDDDDDWWWWWWWW"
"WWWWWDDDDDDDDDDDDWWWWZWW"
"WWWWDDDDDDDDDDDDDDWWWWWW"
"WWWDDDDWWWDDDDDDDDDWWWWW"
"WWWWDDDDDWWDDDDDDDDDWWWW"
"WWWWWDDDDDDDDDDDDDDWWWWW"
"WWWWWWDDDDDDDDDDDDWWWWWW"
"WWWWWWWDDDDDDDDDDWWWWWWW"
"WWWWWWWWDDDDDDDDWWWWWWWW"
"WWWWWWWWWWDDDDDWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
;

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(16.0f / 9.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{

}


void Sandbox2D::OnAttach()
{
	RAINBOW_PROFILE_FUNCTION();
	m_CheckerboardTexture = Rainbow::Texture2D::Create("assets/textures/Checkerboard.png");
	m_SpriteSheet = Rainbow::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");
	m_WinterSheet = Rainbow::Texture2D::Create("assets/game/textures/winter.png");
	m_NPCSheet = Rainbow::Texture2D::Create("assets/game/textures/NPC_test.png");
	m_CharacterSheet = Rainbow::Texture2D::Create("assets/game/textures/character.png");
	m_OgreSheet = Rainbow::Texture2D::Create("assets/game/textures/ogre.png");

	m_TextureStairs = Rainbow::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128, 128 });
	m_TextureTree = Rainbow::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, { 1, 2 });
	m_TextureOgre = Rainbow::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, { 1, 2 });
	

	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles) / s_MapWidth;

	//m_TextureMap['D'] = Rainbow::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 11 }, { 128, 128 });
	//m_TextureMap['W'] = Rainbow::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 11, 11 }, { 128, 128 });
	m_TextureMap['D'] = Rainbow::SubTexture2D::CreateFromCoords(m_WinterSheet, { 0, 6 }, { 32, 32 }, { 1.0f, 1.0f }, 1.0f);
	m_TextureMap['W'] = Rainbow::SubTexture2D::CreateFromCoords(m_WinterSheet, { 1, 1 }, { 32, 32 }, { 1.0f, 1.0f }, 1.0f);

	for (int i = 0; i < 4; i++ )
		m_OgreArray[i] = Rainbow::SubTexture2D::CreateFromCoords(m_OgreSheet, { 0, i }, { 64, 64 });

	// Particle Init
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 1.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };

	m_CameraController.SetZoomLevel(5.0f);
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
#if 0
	{
		RAINBOW_PROFILE_SCOPE("Renderer Draw");
		static float rotation = 0.0f;
		rotation += ts * 20.0f;

		Rainbow::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Rainbow::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(4 * rotation), { 0.8f, 0.2f, 0.3f, 1.0f });
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
				Rainbow::Renderer2D::DrawRotatedQuad({ x, y }, { 0.45f, 0.45f }, glm::radians(rotation * (1 - (y + 5.0f) / 10.0f)), color);
			}
		}

		Rainbow::Renderer2D::EndScene();

	}
#endif

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
		for (int i = 0; i < 5; i++)
			m_ParticleSystem.Emit(m_Particle);
	}


	m_ParticleSystem.OnUpdate(ts);
	m_ParticleSystem.OnRender(m_CameraController.GetCamera());


	Rainbow::Renderer2D::BeginScene(m_CameraController.GetCamera());
	/*
	for (uint32_t y = 0; y < m_MapHeight; y++)
	{
		for (uint32_t x = 0; x < m_MapWidth; x++)
		{
			char tileType = s_MapTiles[x + y * m_MapWidth];
			Rainbow::Ref<Rainbow::SubTexture2D> texture;

			if (m_TextureMap.find(tileType) != m_TextureMap.end())
				texture = m_TextureMap[tileType];
			else
				texture = m_TextureStairs;
			Rainbow::Renderer2D::DrawQuad({ x - m_MapWidth / 2.0f, y - m_MapHeight / 2.0f, 0.5f }, { 1.0f, 1.0f }, texture);

		}
	}
	*/


	//Rainbow::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureStairs);
	//Rainbow::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureBarrel);
	//Rainbow::Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.5f }, { 1.0f, 2.0f }, m_TextureTree);
	Rainbow::Renderer2D::EndScene();


	//static glm::vec2 ogrePos = { 0, 0 };
	Rainbow::Renderer2D::BeginScene(m_CameraController.GetCamera());
	time += 8*ts.GetSeconds();

	Rainbow::Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.5f }, { 1.0f, 1.08f }, m_OgreArray[(int)(time) % 4]);
	Rainbow::Renderer2D::EndScene();

	

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
