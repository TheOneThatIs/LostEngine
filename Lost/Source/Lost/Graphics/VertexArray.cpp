#include"VertexArray.h"
#include<GL\glew.h>
#include"Renderer.h"
#include"VertexBufferLayout.h"

namespace Lost {

VertexArray::VertexArray(){
	GLCALL(glGenVertexArrays(1, &vao));
}
VertexArray::~VertexArray() {
	GLCALL(glDeleteVertexArrays(1, &vao));
}

void VertexArray::addBuffer(const VertexBuffer &vertBuffer, const VertexBufferLayout &layout) {
	bind();
	vertBuffer.bind();
	const auto &elements = layout.getElements();
	unsigned int offset = 0;
	for(unsigned int i = 0; i < elements.size(); i++) {
		const auto &element = elements[i];
		GLCALL(glEnableVertexAttribArray(i));
		GLCALL(glVertexAttribPointer(i, element.count, element.type, element.isNormalized, layout.getStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::getTypeSize(element.type);
	}
}

void VertexArray::bind() const {
	GLCALL(glBindVertexArray(vao));
}
void VertexArray::unbind() const {
	GLCALL(glBindVertexArray(0));
}

}