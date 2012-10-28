#include "World.h"
#include "GameManager.h"

World::World()
{
	_pos = Vector3D<float>(.0f, .0f, .0f);
}

World::~World()
{

}

void World::Init()
{
	GLfloat x = 0;
	GLfloat y = 0;

	// Horizontal coords
	GLfloat z = 0.0f;
	GLfloat left = -2.0f;
	GLfloat right = 2.8f;
	vertices[0] = -100;
	vertices[1] = 0;
	vertices[2] = GameManager::ZNEAR;

	vertices[3] = 100;
	vertices[4] = 0;
	vertices[5] = GameManager::ZNEAR;
	// Creates the lines on the z axis.
	/*for(int i = 0, j = 0; i < 14; ++i, ++j)
	{
		x += 0.2f;

		vertices[j] = x;
		vertices[++j] = y;
		vertices[++j] = GameManager::ZNEAR;

		vertices[++j] = x;
		vertices[++j] = y;
		vertices[++j] = -GameManager::ZFAR;
	}

	// Create the lines on the x axis.
	for(int i = 0, j = 0; i < 40; ++i, ++j)
	{
		z -= 2.0f;

		vertices[j] = right;
		vertices[++j] = left;
		vertices[++j] = z;

		vertices[++j] = right;
		vertices[++j] = left;
		vertices[++j] = z;
	}
	*/
}

void World::Render()
{
	glPushMatrix();
	glLoadIdentity();
	//glTranslatef(_pos.X(), _pos.Y(), _pos.Z());
		glTranslatef(0.0f, 0.0f, -5.0f);
		//glRotatef(180, 1, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);    // enable vertex arrays
		glVertexPointer(3, GL_FLOAT, 0, vertices);     // sette vertex pointer
		glDrawArrays (GL_LINES, 0, 1); // tegne 1 trekant
		glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}