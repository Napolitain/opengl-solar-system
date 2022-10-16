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
		explicit VBO(const std::vector<float> &vertices, bool colors, bool texture);
		VBO(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, bool colors,
			bool texture);
		GLuint getID() const;
		void bind(const std::vector<float> &vertices, bool colors, bool texture) const;

	};
	// END VBO ===================

	GLuint id;
	std::vector<VBO> VBOs;

public:
	VAO();
	GLuint getID() const;
	void bind() const;
	void unbind();
	void createVBO(const std::vector<float> &vertices, bool colors, bool texture);
	void
	createVBO(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, bool colors, bool texture);
	std::vector<VBO> getVBOs();
	void draw(int n, bool strip);

};


#endif //GLITTER_VAO_HPP
