#pragma once


namespace Lost {
class VertexBuffer {
	unsigned int vbo;
public:
	VertexBuffer();
	VertexBuffer(const void *data, unsigned int size);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};
}