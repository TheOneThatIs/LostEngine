#include"Shader.h"
#include<fstream>
#include"Log.h"
#include<GL/glew.h>
#include<sstream>
#include"Renderer.h"

namespace Lost {

	Shader::Shader() {

	}

	Shader::Shader(const std::string &vertShaderFilepath, const std::string &fragShaderFilepath) {
		std::string vertSrc = loadShader(vertShaderFilepath);
		std::string fragSrc = loadShader(fragShaderFilepath);

		unsigned int vertShader = compileShader(GL_VERTEX_SHADER, vertSrc.c_str());
		unsigned int fragShader = compileShader(GL_FRAGMENT_SHADER, fragSrc.c_str());

		program = glCreateProgram();
		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);
		glValidateProgram(program);
		
		glDeleteShader(vertShader);
		glDeleteShader(fragShader);
	}
	Shader::~Shader() {
		glDeleteProgram(program);
	}

	void Shader::bind() const {
		GLCALL(glUseProgram(program));
	}
	void Shader::unbind() const {
		GLCALL(glUseProgram(0));
	}

	std::string Shader::loadShader(std::string filepath) {
		std::ifstream inFile(filepath);

		std::string line;
		std::stringstream ss;
		while(getline(inFile, line)) {
			ss << line << '\n';
		}

		return ss.str();
	}

	unsigned int Shader::compileShader(unsigned int shaderType, const std::string &shaderSrc) {
		unsigned int shader = glCreateShader(shaderType);
		const char *source = shaderSrc.c_str();

		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);

		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(!success) {
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			Log::error( (shaderType == GL_VERTEX_SHADER ? std::string("VERTEX") : std::string("FRAGMENT")) + " SHADER COMPILATION FAILED\n" + std::string(infoLog));
			glDeleteShader(shader);
			return 0;
		}
		return shader;
	}

	void Shader::setUniform4f(const std::string &name, float f1, float f2, float f3, float f4) {
		GLCALL(glUniform4f(getUniformLocation(name), f1, f2, f3, f4));
	}
	unsigned int Shader::getUniformLocation(const std::string &name) {
		if(uniformLocationCache.find(name) != uniformLocationCache.end())
			return uniformLocationCache[name];

		GLCALL(int location = glGetUniformLocation(program, name.c_str()));
		if(location == -1)
			Log::warn("Uniform " + name + " doesn't exist!");
		
		uniformLocationCache[name] = location;

		return location;
	}

}