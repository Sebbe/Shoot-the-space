#include "Spaceship.h"
#include <SDL.h>
#include "GameManager.h"
#include "Bullet.h"

Spaceship::Spaceship(InputManager *inputManager) {
	input = inputManager;
	movementPS = 0.3;
	//vertex 1 (top)
	vertices[0] = 0.0f;
	vertices[1] = 0.5f;
	vertices[2] = 0.0f;
	//vertex 2 (bottom left)
	vertices[3] = -0.5f;
	vertices[4] = -0.5f;
	vertices[5] = 0.0f;
	//vertex 3 (bottom right)
	vertices[6] = 0.5f;
	vertices[7] = -0.5f;
	vertices[8] = 0.0f;

	x = z = 0;
	y = -0.8;
}

void Spaceship::Update(double deltaTime) {
	Move(deltaTime);

	if(input->IsKeyPressed(SDLK_SPACE)) {
		Shoot();
	}
}

void Spaceship::Render() {
	glPushMatrix();
		glTranslatef(x, y, 0.0);
		glScalef(0.1, 0.1, 0.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		glEnableClientState(GL_VERTEX_ARRAY);    // enable vertex arrays
		glVertexPointer(3, GL_FLOAT, 0, vertices);     // sette vertex pointer
		glDrawArrays (GL_TRIANGLES, 0, 3);                  // tegne 1 trekant
		glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays      
	glPopMatrix();
}

void Spaceship::Shoot() {
	Bullet *temp = new Bullet(x, y, z);
	GameManager::renderList.push_back(temp);
}

void Spaceship::Move(double deltaTime) {
	if(input->IsKeyDown(SDLK_a) && x >= -0.95) {
		x -= movementPS * static_cast<GLfloat>(deltaTime);
	}
	if(input->IsKeyDown(SDLK_d) && x <= 0.95) {
		x += movementPS * static_cast<GLfloat>(deltaTime);
	}
	if(input->IsKeyDown(SDLK_w)) {
		y += movementPS * static_cast<GLfloat>(deltaTime);
	}
	if(input->IsKeyDown(SDLK_s)) {
		y -= movementPS * static_cast<GLfloat>(deltaTime);
	}
}

Spaceship::~Spaceship() {
}