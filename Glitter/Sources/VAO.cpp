//
// Created by Maxime Boucher on 14/10/2022.
//

#include "VAO.hpp"
#include "glad/glad.h"

// VBO ==========================

VAO::VBO::VBO(float *vertices) {
	glGenBuffers(1, &id);
	bind(vertices);
}

unsigned int VAO::VBO::getID() const {
	return id;
}

void VAO::VBO::bind(float *vertices) const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

// VAO ===========================

VAO::VAO() {
	glGenVertexArrays(1, &id);
}

void VAO::bind() const {
	glBindVertexArray(id);
}

std::vector<VAO::VBO> VAO::getVBOs() {
	return VBOs;
}

unsigned int VAO::getID() const {
	return id;
}

void VAO::createVBO(float *vertices) {
	VBOs.emplace_back(VBO(vertices));
}
