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

VAO::VBO::VBO(const std::vector<float> &vertices, const std::vector<unsigned int> &indices) {
	glGenBuffers(1, &id);
	bind(vertices);
	glGenBuffers(1, &ebo); // EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size(), &indices[0], GL_STATIC_DRAW);
}

unsigned int VAO::VBO::getID() const {
	return id;
}

void VAO::VBO::bind(const std::vector<float>& vertices) const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) nullptr);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (6 * sizeof(float)));
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

void VAO::createVBO(const std::vector<float> &vertices, const std::vector<unsigned int> &indices) {
	VBOs.emplace_back(VBO(vertices, indices));
}

void VAO::draw(int n) {
	glDrawElements(GL_TRIANGLES, n, GL_UNSIGNED_INT, nullptr);
}

