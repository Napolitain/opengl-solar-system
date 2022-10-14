//
// Created by Maxime Boucher on 14/10/2022.
//

#ifndef GLITTER_VAO_HPP
#define GLITTER_VAO_HPP

#include "vector"

class VAO {
	// START VBO =================
	class VBO {
		unsigned int id;

	public:
		explicit VBO(float vertices[]);
		unsigned int getID() const;
		void bind(float *vertices) const;

	};
	// END VBO ===================

	unsigned int id;
	std::vector<VBO> VBOs;

public:
	VAO();
	unsigned int getID() const;
	void bind() const;
	void createVBO(float* vertices);
	std::vector<VBO> getVBOs();

};


#endif //GLITTER_VAO_HPP
