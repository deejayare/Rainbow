#include <Rainbow.h>
#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class ExampleLayer : public Rainbow::Layer
{
public:
	ExampleLayer() 
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition({0.0f, 0.0f, 0.0f})
	{
		m_VertexArray.reset(Rainbow::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.2f, 0.7f, 0.1f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.2f, 0.7f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.7f, 0.1f, 0.1f, 1.0f
		};

		Rainbow::Ref<Rainbow::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Rainbow::VertexBuffer::Create(vertices, sizeof(vertices)));

		Rainbow::BufferLayout layout = {
			{ Rainbow::ShaderDataType::Float3, "a_Position"},
			{ Rainbow::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Rainbow::Ref<Rainbow::IndexBuffer> indexBuffer;
		indexBuffer.reset(Rainbow::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		m_SquareVA.reset(Rainbow::VertexArray::Create());


		float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Rainbow::Ref<Rainbow::VertexBuffer> squareVB;
		squareVB.reset(Rainbow::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));


		squareVB->SetLayout({
			{ Rainbow::ShaderDataType::Float3, "a_Position" },
			{ Rainbow::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };

		Rainbow::Ref<Rainbow::IndexBuffer> squareIB;
		squareIB.reset(Rainbow::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

		m_SquareVA->SetIndexBuffer(squareIB);


		std::string vertexSrc = R"(
		#version 330 core
	
		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec4 a_Color;

		uniform mat4 u_ViewProjection;
		uniform mat4 u_Transform;

		out vec3 v_Position;
		out vec4 v_color;

		void main()
		{
			v_Position = a_Position;
			gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			v_color = a_Color;
		}
		)";

		std::string fragmentSrc = R"(
		#version 330 core
	
		layout(location = 0) out vec4 color;

		in vec3 v_Position;
		in vec4 v_color;

		void main()
		{
			color = vec4(v_Position * 0.5 + 0.5, 1.0);
			color = v_color;
		}


		)";

		m_Shader.reset(Rainbow::Shader::Create(vertexSrc, fragmentSrc));

		

		std::string flatColorShaderVertexSrc = R"(
		#version 330 core
	
		layout(location = 0) in vec3 a_Position;

		uniform mat4 u_ViewProjection;
		uniform mat4 u_Transform;

		out vec3 v_Position;

		void main()
		{
			v_Position = a_Position;
			gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
		}
		)";

		std::string flatColorShaderFragmentSrc = R"(
		#version 330 core
	
		layout(location = 0) out vec4 color;

		in vec3 v_Position;

		uniform vec3 u_Color;

		void main()
		{
			color = vec4(u_Color, 1.0f);
		}


		)";

		m_FlatColorShader.reset(Rainbow::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));




		m_TextureShader.reset(Rainbow::Shader::Create("assets/shaders/Texture.glsl"));

		m_Texture = Rainbow::Texture2D::Create("assets/textures/Checkerboard.png");
		m_HeartTexture = Rainbow::Texture2D::Create("assets/textures/test.png");


		std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_TextureShader)->UploadUniformInt("m_Texture", 0);

	}

	void OnUpdate(Rainbow::Timestep ts) override
	{
		RAINBOW_TRACE("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());

		if (Rainbow::Input::IsKeyPressed(RAINBOW_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;

		else if (Rainbow::Input::IsKeyPressed(RAINBOW_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Rainbow::Input::IsKeyPressed(RAINBOW_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		else if (Rainbow::Input::IsKeyPressed(RAINBOW_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Rainbow::Input::IsKeyPressed(RAINBOW_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (Rainbow::Input::IsKeyPressed(RAINBOW_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;


		Rainbow::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Rainbow::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Rainbow::Renderer::BeginScene(m_Camera);

		static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));


		std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Rainbow::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Rainbow::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		m_Texture->Bind();
		Rainbow::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_HeartTexture->Bind();
		Rainbow::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


		// Triangle
		//Rainbow::Renderer::Submit(m_Shader, m_VertexArray);

		Rainbow::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");

		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));

		ImGui::End();
	}

	void OnEvent(Rainbow::Event& event) override 
	{
	}



private:
	Rainbow::Ref<Rainbow::Shader> m_Shader;
	Rainbow::Ref<Rainbow::VertexArray> m_VertexArray;

	Rainbow::Ref<Rainbow::Shader> m_FlatColorShader, m_TextureShader;
	Rainbow::Ref<Rainbow::VertexArray> m_SquareVA;

	Rainbow::Ref<Rainbow::Texture2D> m_Texture, m_HeartTexture;

	Rainbow::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 3.0f;
	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
	glm::vec3 m_SquareColor = { 0.2f, 0.3, 0.8f };

};

class Sandbox : public Rainbow::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{


	}



};

Rainbow::Application* Rainbow::CreateApplication()
{
	return new Sandbox();
}