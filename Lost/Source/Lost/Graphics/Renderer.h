#pragma once
#include"VertexArray.h"
#include"IndexBuffer.h"
#include"Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCALL(x) glClearErrors(); x; ASSERT(glLogCall(#x, __FILE__, __LINE__))


namespace Lost {
	void glClearErrors();
	bool glLogCall(const char *function, const char *file, int line);

	class Renderer {
	public:
		Renderer();

		void render(const VertexArray &vao, const IndexBuffer &ibo, const Shader &shader) const;
		void clear() const;
	};
};