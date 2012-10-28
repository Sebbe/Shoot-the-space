#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "GLUtils/GLUtils.hpp"
#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>
#include <stdexcept>
#include "input/InputManager.h"
#include "Utils\Vector3D.h"

using std::cerr;
using std::endl;
using GLUtils::checkGLErrors;

class Renderable {
public:
	Renderable() {}
	virtual ~Renderable() {}
	virtual void Render() {
		std::cout << "test";
	}

	virtual void Update(double deltaTime) {
		std::cout << "feil ";
	};

	virtual bool Delete() {
		return false;
	}

	void SetPosition(Vector3D<float> pos) {
		this->pos = pos;
	}

	GLfloat inline getX() { return x; }
	GLfloat inline getY() { return y; }
	GLfloat inline getZ() { return z; }
protected:
	GLfloat movementPS;
	Vector3D<float> pos;
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

#endif