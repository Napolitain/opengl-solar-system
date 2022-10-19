//
// Created by Maxime Boucher on 16/10/2022.
//

#ifndef GLITTER_GAMEOBJECT_HPP
#define GLITTER_GAMEOBJECT_HPP


#include "glm/vec3.hpp"
#include "vector"
#include "VAO.hpp"
#include "glm/glm.hpp"

class GameObject {
	glm::mat4 model = glm::mat4(1.0f);
	VAO vao;
	int size;

public:
	glm::vec3 position;

	explicit GameObject(glm::vec3 position);
	void loadVertices(const std::vector<float>& vertices, bool colors, bool texture);
	void draw();
	glm::mat4 getModel() const;

};


#endif //GLITTER_GAMEOBJECT_HPP
