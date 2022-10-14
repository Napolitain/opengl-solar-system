//
// Created by Maxime Boucher on 14/10/2022.
//

#ifndef GLITTER_VAO_HPP
#define GLITTER_VAO_HPP

#include "vector"
#include "glad/glad.h"

class VAO {
	// START VBO =================
	class VBO {
		GLuint id;

	public:
		explicit VBO(float vertices[]);
		GLuint getID() const;
		void bind(float *vertices) const;

	};
	// END VBO ===================

	GLuint id;
	std::vector<VBO> VBOs;

public:
	VAO();
	GLuint getID() const;
	void bind() const;
	void unbind();
	void createVBO(float* vertices);
	std::vector<VBO> getVBOs();

};


#endif //GLITTER_VAO_HPP
