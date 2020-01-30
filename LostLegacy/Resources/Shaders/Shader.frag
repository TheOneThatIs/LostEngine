#version 330 core

layout(location = 0) out vec4 color;

in vec2 vTextureCoord;

uniform vec4 uColor;
uniform sampler2D uTexture;


void main() {
	vec4 textureColor = texture(uTexture, vTextureCoord);
    color = textureColor;
}