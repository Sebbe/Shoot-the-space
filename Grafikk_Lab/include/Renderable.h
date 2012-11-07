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
	/**
	 *
	 *
	 */
	Renderable() {}
	virtual ~Renderable() {}
	
	/**
	 *
	 *
	 */
	virtual void Render() {
		std::cout << "test";
	}

	/**
	 *
	 *
	 */
	virtual void Update(double deltaTime) {
		std::cout << "feil ";
	};

	/**
	 *
	 *
	 */
	virtual bool Delete() {
		return false;
	}

	/**
	 * Sets postion
	 *
	 */
	void SetPosition(Vector3D<GLfloat> pos) {
		this->pos = pos;
	}

	/**
	 * Helper functions to get x y and z
	 * 
	 */
	Vector3D<GLfloat> inline getPos() { return pos; }
	GLfloat inline getX() { return pos.X(); }
	GLfloat inline getY() { return pos.Y(); }
	GLfloat inline getZ() { return pos.Z(); }
protected:
	/* Decides how fast things will move */
	GLfloat movementPS;
	/* Position */
	Vector3D<GLfloat> pos;
};

#endif