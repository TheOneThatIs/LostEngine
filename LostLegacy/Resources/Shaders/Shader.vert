#version 330 core

layout(location = 0) in vec4 pos;
layout(location = 1) in vec2 textureCoord;

out vec2 vTextureCoord;
uniform mat4 uModelViewProjectionMatrix;

void main() {
    gl_Position = pos * uModelViewProjectionMatrix;
	vTextureCoord = textureCoord;
}