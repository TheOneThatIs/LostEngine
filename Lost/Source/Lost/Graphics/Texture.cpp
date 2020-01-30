#include"Texture.h"
#include"GL/glew.h"
#include<STBImage/STBImage.h>

namespace Lost {

Texture::Texture(const std::string &filepath) : textureID(0), filepath(filepath), localBuffer(nullptr), width(0), height(0), bitsPerPixel(0){
	stbi_set_flip_vertically_on_load(1);
	localBuffer = stbi_load(filepath.c_str(), &width, &height, &bitsPerPixel, 4);

	GLCALL(glGenTextures(1, &textureID));
	GLCALL(glBindTexture(GL_TEXTURE_2D, textureID));

	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP));

	GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));

	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));

	if(localBuffer)
		stbi_image_free(localBuffer);
}
Texture::~Texture() {
	GLCALL(glDeleteTextures(1, &textureID))
}

void Texture::bind(unsigned int slot) const {
	GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
	GLCALL(glBindTexture(GL_TEXTURE_2D, textureID));
}
void Texture::unbind() const {
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

inline int Texture::getWidth() const {

}
inline int Texture::getHeight() const {

}

}