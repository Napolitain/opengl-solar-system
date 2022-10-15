//
// Created by Maxime Boucher on 14/10/2022.
//

#include "VAO.hpp"
#include "iostream"
#include "glad/glad.h"

// VBO ==========================

VAO::VBO::VBO(const std::vector<float>& vertices) {
	glGenBuffers(1, &id);
	bind(vertices);
}

unsigned int VAO::VBO::getID() const {
	return id;
}

void VAO::VBO::bind(const std::vector<float>& vertices) const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) nullptr);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

// VAO ===========================

VAO::VAO() {
	glGenVertexArrays(1, &id);
}

void VAO::bind() const {
	glBindVertexArray(id);
}

void VAO::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

std::vector<VAO::VBO> VAO::getVBOs() {
	return VBOs;
}

unsigned int VAO::getID() const {
	return id;
}

void VAO::createVBO(const std::vector<float>& vertices) {
	VBOs.emplace_back(VBO(vertices));
}
