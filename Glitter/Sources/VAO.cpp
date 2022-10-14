//
// Created by Maxime Boucher on 14/10/2022.
//

#include "VAO.hpp"
#include "iostream"
#include "glad/glad.h"

// VBO ==========================

VAO::VBO::VBO(float *vertices) {
	glGenBuffers(1, &id);
	std::cout << "VBO(" << id << "): created." << std::endl;
	bind(vertices);
}

unsigned int VAO::VBO::getID() const {
	return id;
}

void VAO::VBO::bind(float *vertices) const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) nullptr);
	glEnableVertexAttribArray(0);
	std::cout << "VBO(" << id << "): binded and data copied." << std::endl;
}

// VAO ===========================

VAO::VAO() {
	glGenVertexArrays(1, &id);
	std::cout << "VAO(" << id << "): created." << std::endl;
}

void VAO::bind() const {
	glBindVertexArray(id);
	std::cout << "VAO(" << id << "): binded." << std::endl;
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

void VAO::createVBO(float *vertices) {
	VBOs.emplace_back(VBO(vertices));
}
