//
// Created by Maxime Boucher on 16/10/2022.
//

#include "GameObject.hpp"
#include "VAO.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "GLFW/glfw3.h"
#include <iostream>

GameObject::GameObject() = default;

void GameObject::loadVertices(const std::vector<float> &vertices, bool colors, bool texture) {
	vao.bind();
	vao.createVBO(vertices, colors, texture);
	vao.unbind();
	size = vertices.size();
}

void GameObject::draw() {
	this->transform.model = getModel();
	vao.draw(size, false);
}

glm::mat4 GameObject::getModel() const {
	// translation * rotation * scale (also known as TRS matrix)
	return glm::translate(glm::mat4(1.0f), this->transform.position) *
		glm::rotate(glm::mat4(1.0f), 1.0f, this->transform.rotation) *
		glm::scale(glm::mat4(1.0f), this->transform.scale);
}

void GameObject::addChild(GameObject *gameObject) {
	gameObject->parent = this;
	children.emplace_back(gameObject);
}
