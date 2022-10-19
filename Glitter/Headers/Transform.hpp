//
// Created by Maxime Boucher on 19/10/2022.
//

#ifndef GLITTER_TRANSFORM_HPP
#define GLITTER_TRANSFORM_HPP


#include "glm/vec3.hpp"
#include "glm/detail/type_mat4x4.hpp"

struct Transform {

	glm::vec3 position = { 0.0f, 3.0f, 0.0f };
	glm::vec3 rotation = { 0.0f, 1.0f, 0.0f };
	glm::vec3 scale = { 1.0f, 1.0f, 1.0f };
	glm::mat4 model = glm::mat4(1.0f);

};


#endif //GLITTER_TRANSFORM_HPP
