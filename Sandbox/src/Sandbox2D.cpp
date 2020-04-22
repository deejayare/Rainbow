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


	m_SquareVA = Rainbow::VertexArray::Create();


	float squareVertices[5 * 4] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f
	};

	Rainbow::Ref<Rainbow::VertexBuffer> squareVB;
	squareVB.reset(Rainbow::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));


	squareVB->SetLayout({
		{ Rainbow::ShaderDataType::Float3, "a_Position" }
		});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };

	Rainbow::Ref<Rainbow::IndexBuffer> squareIB;
	squareIB.reset(Rainbow::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

	m_SquareVA->SetIndexBuffer(squareIB);


	m_FlatColorShader = Rainbow::Shader::Create("assets/shaders/FlatColor.glsl");

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


	Rainbow::Renderer::BeginScene(m_CameraController.GetCamera());



	std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Rainbow::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));



	Rainbow::Renderer::EndScene();
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
