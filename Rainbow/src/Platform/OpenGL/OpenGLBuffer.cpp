#include "rbpch.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#include <glad/glad.h> 

namespace Rainbow {


	/////////////////////////////////////////////////////////////////////////////////
	// VertexBuffer /////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	Rainbow::OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
	{
		RAINBOW_PROFILE_FUNCTION();
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		RAINBOW_PROFILE_FUNCTION();
		glDeleteBuffers(1, &m_RendererID);
	}

	void Rainbow::OpenGLVertexBuffer::Bind() const
	{
		RAINBOW_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void Rainbow::OpenGLVertexBuffer::Unbind() const
	{
		RAINBOW_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/////////////////////////////////////////////////////////////////////////////////
	// IndexBuffer //////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////

	Rainbow::OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count) 
		: m_Count(count)
	{
		RAINBOW_PROFILE_FUNCTION();
		glCreateBuffers(1, &m_RendererID);

		// GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
		// Binding with GL_ARRAY_BUFFER instead allows the data to be loaded even with no bound VAO
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		RAINBOW_PROFILE_FUNCTION();
		glDeleteBuffers(1, &m_RendererID);
	}

	void Rainbow::OpenGLIndexBuffer::Bind() const
	{
		RAINBOW_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void Rainbow::OpenGLIndexBuffer::Unbind() const
	{
		RAINBOW_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}