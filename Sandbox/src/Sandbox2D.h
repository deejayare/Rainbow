#pragma once
#include "Rainbow.h"
#include "ParticleSystem.h"

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

	Rainbow::Ref<Rainbow::Texture2D> m_CheckerboardTexture;
	Rainbow::Ref<Rainbow::Texture2D> m_SpriteSheet, m_WinterSheet;
	Rainbow::Ref<Rainbow::Texture2D> m_NPCSheet;
	Rainbow::Ref<Rainbow::Texture2D> m_CharacterSheet;
	Rainbow::Ref<Rainbow::Texture2D> m_OgreSheet;
	Rainbow::Ref<Rainbow::SubTexture2D> m_TextureStairs, m_TextureBarrel, m_TextureTree, m_TextureOgre;


	glm::vec4 m_SquareColor = { 0.2f, 0.3, 0.8f, 1.0f };

	ParticleProps m_Particle;
	ParticleSystem m_ParticleSystem;

	uint32_t m_MapWidth, m_MapHeight;
	std::unordered_map<char, Rainbow::Ref<Rainbow::SubTexture2D>> m_TextureMap;
	Rainbow::Ref<Rainbow::SubTexture2D> m_OgreArray[9];
	float time = 1;
};