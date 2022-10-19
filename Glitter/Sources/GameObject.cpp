//
// Created by Maxime Boucher on 16/10/2022.
//

#include "GameObject.hpp"
#include "VAO.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "GLFW/glfw3.h"

GameObject::GameObject(glm::vec3 position) {
	this->position = position;
}

void GameObject::loadVertices(const std::vector<float> &vertices, bool colors, bool texture) {
	vao.bind();
	vao.createVBO(vertices, colors, texture);
	vao.unbind();
	size = vertices.size();
}

void GameObject::draw() {
	this->model = glm::translate(glm::mat4(1.0f), position);
	this->model = glm::rotate(model, (float) glfwGetTime(), glm::vec3(0.5f, 1.0f, 1.0f));
	vao.draw(size, false);
}

glm::mat4 GameObject::getModel() const {
	return model;
}
