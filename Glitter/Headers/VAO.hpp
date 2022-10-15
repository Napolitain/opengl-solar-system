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
		GLuint ebo;

	public:
		explicit VBO(const std::vector<float>& vertices);
		VBO(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
		GLuint getID() const;
		void bind(const std::vector<float>& vertices) const;

	};
	// END VBO ===================

	GLuint id;
	std::vector<VBO> VBOs;

public:
	VAO();
	GLuint getID() const;
	void bind() const;
	void unbind();
	void createVBO(const std::vector<float>& vertices);
	void createVBO(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
	std::vector<VBO> getVBOs();
	void draw(int n, bool strip);

};


#endif //GLITTER_VAO_HPP
