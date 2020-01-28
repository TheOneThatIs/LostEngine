#pragma once
#include"VertexBuffer.h"

namespace Lost {
class VertexBufferLayout;

class VertexArray {
	unsigned int vao;
public:
	VertexArray();
	~VertexArray();

	void addBuffer(const VertexBuffer &vertBuffer, const VertexBufferLayout &layout);

	void bind() const;
	void unbind() const;
};
}