#include"Renderer.h"
#include<GL/glew.h>
#include<iostream>

namespace Lost {
	void glClearErrors() {
		//while(glGetError() != GL_NO_ERROR);
	}
	bool glLogCall(const char *function, const char *file, int line) {
		while(GLenum error = glGetError()) {
			std::cout << "[OpenGL Error]" << function << " " << file << ": Line " << line << " Error Code: " << error << std::endl;
			return false;
		}
		return true;
	}

	Renderer::Renderer() {
		
	}

	void Renderer::render(const VertexArray &vao, const IndexBuffer &ibo, const Shader &shader) const {
		shader.bind();
		vao.bind();
		ibo.bind();

		GLCALL(glClearColor(0.1f, 0.1f, 0.1f, 1.0f));
		GLCALL(glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr));

	}

	void Renderer::clear() const {
		GLCALL(glClear(GL_COLOR_BUFFER_BIT));
	}
}