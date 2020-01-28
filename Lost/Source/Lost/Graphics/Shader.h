#pragma once
#include<string>
#include<unordered_map>

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

	void setUniform4f(const std::string& name, float f1, float f2, float f3, float f4);

private:
	unsigned int compileShader(unsigned int shaderType, const std::string &shaderSrc);
	unsigned int getUniformLocation(const std::string &name);
};

}