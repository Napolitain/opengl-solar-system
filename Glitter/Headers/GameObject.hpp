//
// Created by Maxime Boucher on 16/10/2022.
//

#ifndef GLITTER_GAMEOBJECT_HPP
#define GLITTER_GAMEOBJECT_HPP


#include "vector"
#include "VAO.hpp"
#include "glm/glm.hpp"
#include "Transform.hpp"

class GameObject {
	VAO vao;
	int size;
	GameObject* parent = nullptr;
	std::vector<GameObject*> children;

public:
	Transform transform;

	GameObject();
	void loadVertices(const std::vector<float>& vertices, bool colors, bool texture);
	void draw();
	glm::mat4 getModel() const;
	void addChild(GameObject* gameObject);

};


#endif //GLITTER_GAMEOBJECT_HPP
