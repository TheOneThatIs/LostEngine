#pragma once
#include<string>
#include<unordered_map>
#include"GLM/glm/glm.hpp"

namespace Lost {

class Shader {
	unsigned int program;
	std::unordered_map<std::string, int> uniformLocationCache;
public:
	Shader();
	Shader(const std::string &vertShaderFilepath, const std::string &fragShaderFilepath);
	~Shader();

	void bind() const;
	void unbind() const;

	std::string loadShader(std::string filepath);

	void setUniform1i(const std::string &name, int i1);
	void setUniform1f(const std::string &name, float f1);
	void setUniform4f(const std::string& name, float f1, float f2, float f3, float f4);
	void setUniformMat4f(const std::string &name, const glm::mat4 & matrix);

private:
	unsigned int compileShader(unsigned int shaderType, const std::string &shaderSrc);
	int getUniformLocation(const std::string &name);
};

}