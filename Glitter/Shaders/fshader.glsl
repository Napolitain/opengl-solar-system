#version 410 core

in vec3 ourColor;
in vec2 texCoord;
out vec4 color;

uniform sampler2D ourTexture;

void main() {
    color = vec4(ourColor, 1.0f);
}
