#include "Spaceship.h"
#include <SDL.h>
#include "GameManager.h"
#include "Bullet.h"

Spaceship::Spaceship(InputManager *inputManager, Bulletpool *bulletpool) {
	input = inputManager;
	this->bulletpool = bulletpool;
	movementPS = 0.3;
	// bottom
	//vertex 1 (top)
	vertices[0] = 0.0f;
	vertices[1] = 0.5f;
	vertices[2] = -1.0f;
	//vertex 2 (bottom left)
	vertices[3] = -1.0f;
	vertices[4] = 0.5f;
	vertices[5] = 1.0f;
	//vertex 3 (bottom right)
	vertices[6] = 1.0f;
	vertices[7] = 0.5f;
	vertices[8] = 1.0f;

	// bottom
	// top
	vertices[9] = 0.0f;
	vertices[10] = -0.5f;
	vertices[11] = -1.0f;
	//vertex 2 (bottom left)
	vertices[12] = 1.0f;
	vertices[13] = -0.5f;
	vertices[14] = 1.0f;
	//vertex 3 (bottom right)
	vertices[15] = -1.0f;
	vertices[16] = -0.5f;
	vertices[17] = 1.0f;

	//middle front
	// top right
	vertices[18] = 1.0f;
	vertices[19] = 0.5f;
	vertices[20] = 1.0f;
	// top left
	vertices[21] = -1.0f;
	vertices[22] = 0.5f;
	vertices[23] = 1.0f;
	// bottom left
	vertices[24] = -1.0f;
	vertices[25] = -0.5f;
	vertices[26] = 1.0f;
	// bottom right
	vertices[27] = 1.0f;
	vertices[28] = -0.5f;
	vertices[29] = 1.0f;

	//left side
	// top right
	vertices[30] = -1.0f;
	vertices[31] = 0.5f;
	vertices[32] = 1.0f;
	// top left
	vertices[33] = 0.0f;
	vertices[34] = 0.5f;
	vertices[35] = -1.0f;
	// bottom left
	vertices[36] = 0.0f;
	vertices[37] = -0.5f;
	vertices[38] = -1.0f;
	// bottom right
	vertices[39] = -1.0f;
	vertices[40] = -0.5f;
	vertices[41] = 1.0f;

	// right side
	vertices[30] = 1.0f;
	vertices[31] = 0.5f;
	vertices[32] = 1.0f;
	// top left
	vertices[33] = 0.0f;
	vertices[34] = 0.5f;
	vertices[35] = -1.0f;
	// bottom left
	vertices[36] = 0.0f;
	vertices[37] = -0.5f;
	vertices[38] = -1.0f;
	// bottom right
	vertices[39] = 1.0f;
	vertices[40] = -0.5f;
	vertices[41] = 1.0f;

	/*glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Left)
			glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Left)*/

	x = z = 0;
	z = -2;
	y = -0.8;
}

void Spaceship::Update(double deltaTime) {
	Move(deltaTime);

	if(input->IsKeyPressed(SDLK_SPACE)) {
		Shoot();
	}
}

void Spaceship::Render() {
	glLoadIdentity();
	
	glPushMatrix();
		glTranslatef(x, y, z);
		glScalef(0.1, 0.1, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		//glRotatef(180, 1, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);    // enable vertex arrays
		glVertexPointer(3, GL_FLOAT, 0, vertices);     // sette vertex pointer
		glDrawArrays (GL_TRIANGLES, 0, 3); // tegne 1 trekant
		glDrawArrays(GL_QUADS, 6, 8);
		glColor3f(0.0f, 1.0f, 0.0f);
		glDrawArrays(GL_TRIANGLES, 3, 3);
		glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
	glPopMatrix();
	
	/*
	glPushMatrix();
		glTranslatef(x, y, z);
		glScalef(0.1, 0.1, 0.1);
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);		// Draw The Cube Using quads
			glColor3f(0.0f,1.0f,0.0f);	// Color Blue
			glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Top)
			glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Top)
			glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Quad (Top)
			glVertex3f( 1.0f, 1.0f, 1.0f);	// Bottom Right Of The Quad (Top)
			glColor3f(1.0f,0.5f,0.0f);	// Color Orange
			glVertex3f( 1.0f,-1.0f, 1.0f);	// Top Right Of The Quad (Bottom)
			glVertex3f(-1.0f,-1.0f, 1.0f);	// Top Left Of The Quad (Bottom)
			glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Bottom)
			glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Bottom)
			glColor3f(1.0f,0.0f,0.0f);	// Color Red	
			glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Front)
			glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Front)
			glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Front)
			glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Front)
			glColor3f(1.0f,1.0f,0.0f);	// Color Yellow
			glVertex3f( 1.0f,-1.0f,-1.0f);	// Top Right Of The Quad (Back)
			glVertex3f(-1.0f,-1.0f,-1.0f);	// Top Left Of The Quad (Back)
			glVertex3f(-1.0f, 1.0f,-1.0f);	// Bottom Left Of The Quad (Back)
			glVertex3f( 1.0f, 1.0f,-1.0f);	// Bottom Right Of The Quad (Back)
			glColor3f(0.0f,0.0f,1.0f);	// Color Blue
			glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Left)
			glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Left)
			glColor3f(1.0f,0.0f,1.0f);	// Color Violet
			glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Right)
			glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Right)
			glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Right)
			glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Right)
		glEnd();
	glPopMatrix();
	*/
}

void Spaceship::Shoot() {
	bulletpool->AddBullet(x, y, z);
}

void Spaceship::Move(double deltaTime) {
	if(input->IsKeyDown(SDLK_a)) {
		x -= movementPS * static_cast<GLfloat>(deltaTime);
	}
	if(input->IsKeyDown(SDLK_d)) {
		x += movementPS * static_cast<GLfloat>(deltaTime);
	}
	if(input->IsKeyDown(SDLK_w)) {
		y += movementPS * static_cast<GLfloat>(deltaTime);
	}
	if(input->IsKeyDown(SDLK_s)) {
		y -= movementPS * static_cast<GLfloat>(deltaTime);
	}

	std::cout << "Ship (" << x << ", " << y << ", " << z << ")" << endl;
}

Spaceship::~Spaceship() {
	bulletpool = NULL;
	input = NULL;
}