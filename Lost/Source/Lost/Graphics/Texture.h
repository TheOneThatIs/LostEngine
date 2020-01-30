#pragma once
#include"Renderer.h"
#include<string>

namespace Lost {
class Texture {
	unsigned int textureID;
	std::string filepath;
	unsigned char *localBuffer;
	int width, height, bitsPerPixel;
public:
	Texture(const std::string &filepath);
	~Texture();

	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline int getWidth() const;
	inline int getHeight() const;
};
}