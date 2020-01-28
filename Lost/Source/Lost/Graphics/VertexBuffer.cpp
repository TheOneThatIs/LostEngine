#include"VertexBuffer.h"
#include"Renderer.h"
#include<GL/glew.h>

namespace Lost {
	VertexBuffer::VertexBuffer(){}
	VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
		GLCALL(glGenBuffers(1, &vbo));
		bind();
		GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}
	VertexBuffer::~VertexBuffer(){
		GLCALL(glDeleteBuffers(1, &vbo));
	}

	void VertexBuffer::bind() const {
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	}

	void VertexBuffer::unbind() const {
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}