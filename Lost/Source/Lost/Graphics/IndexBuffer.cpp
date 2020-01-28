#include"IndexBuffer.h"
#include"Renderer.h"
#include<GL/glew.h>

namespace Lost {
	IndexBuffer::IndexBuffer(){}
	IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) : count(count){
		GLCALL(glGenBuffers(1, &ibo));
		bind();
		GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
	}
	IndexBuffer::~IndexBuffer() {
		GLCALL(glDeleteBuffers(1, &ibo));
	}

	void IndexBuffer::bind() const {
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	}

	void IndexBuffer::unbind() const {
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	unsigned int IndexBuffer::getCount() const {
		return count;
	}
}