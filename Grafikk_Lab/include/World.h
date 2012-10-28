#ifndef WORLD_H__
#define WORLD_H__

#include "Renderable.h"
#include "Utils/Vector3D.h"
#include "GLUtils/GLUtils.hpp"
#include <Windows.h>
#include <GL/GL.h>
class World : public Renderable
{
public: 
	World();
	~World();

	void Init();
	void Render();
	
private:
	GLfloat vertices[240];
	Vector3D<float> _pos;
};


#endif