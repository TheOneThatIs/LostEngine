#pragma once


namespace Lost {
class IndexBuffer {
	unsigned int ibo;
	unsigned int count;
public:
	IndexBuffer();
	IndexBuffer(const unsigned int *data, unsigned int count);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	unsigned int getCount() const;
};
}