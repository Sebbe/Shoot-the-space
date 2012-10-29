#include "Spaceship.h"
#include <SDL.h>
#include "GameManager.h"
#include "Bullet.h"
#include "Ship\BaseShip.h"
#include "Utils/Vector3D.h"

Spaceship::Spaceship(InputManager *inputManager, Bulletpool *bulletpool) {
	input = inputManager;
	this->bulletpool = bulletpool;
	movementPS = static_cast<GLfloat>(0.3);
	colBox = Vector3D<float>(0.1f, 0.05f, 0.1f);
	// bottom
	//vertex 1 (top)
	vertices[0] = 0.0f;
	vertices[1] = 1.0f;
	vertices[2] = -1.0f;
	//vertex 2 (bottom left)
	vertices[3] = -1.0f;
	vertices[4] = 1.0f;
	vertices[5] = 1.0f;
	//vertex 3 (bottom right)
	vertices[6] = 1.0f;
	vertices[7] = 1.0f;
	vertices[8] = 1.0f;

	// bottom
	// top
	vertices[9] = 0.0f;
	vertices[10] = -1.0f;
	vertices[11] = -1.0f;
	//vertex 2 (bottom left)
	vertices[12] = 1.0f;
	vertices[13] = -1.0f;
	vertices[14] = 1.0f;
	//vertex 3 (bottom right)
	vertices[15] = -1.0f;
	vertices[16] = -1.0f;
	vertices[17] = 1.0f;

	//middle front
	// top right
	vertices[18] = 1.0f;
	vertices[19] = 1.0f;
	vertices[20] = 1.0f;
	// top left
	vertices[21] = -1.0f;
	vertices[22] = 1.0f;
	vertices[23] = 1.0f;
	// bottom left
	vertices[24] = -1.0f;
	vertices[25] = -1.0f;
	vertices[26] = 1.0f;
	// bottom right
	vertices[27] = 1.0f;
	vertices[28] = -1.0f;
	vertices[29] = 1.0f;

	//left side
	// top right
	vertices[30] = -1.0f;
	vertices[31] = 1.0f;
	vertices[32] = 1.0f;
	// top left
	vertices[33] = 0.0f;
	vertices[34] = 1.0f;
	vertices[35] = -1.0f;
	// bottom left
	vertices[36] = 0.0f;
	vertices[37] = -1.0f;
	vertices[38] = -1.0f;
	// bottom right
	vertices[39] = -1.0f;
	vertices[40] = -1.0f;
	vertices[41] = 1.0f;

	// right side
	vertices[30] = 1.0f;
	vertices[31] = 1.0f;
	vertices[32] = 1.0f;
	// top left
	vertices[33] = 0.0f;
	vertices[34] = 1.0f;
	vertices[35] = -1.0f;
	// bottom left
	vertices[36] = 0.0f;
	vertices[37] = -1.0f;
	vertices[38] = -1.0f;
	// bottom right
	vertices[39] = 1.0f;
	vertices[40] = -1.0f;
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
		glScalef(colBox.X(), colBox.Y(), colBox.Z());
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

}

void Spaceship::Shoot() {
	bulletpool->AddBullet(x, y, z);
}

void Spaceship::Move(double deltaTime) {
	if(input->IsKeyDown(SDLK_a)) {
		float temp = x - movementPS * static_cast<GLfloat>(deltaTime);
		if(!CheckCollision(Vector3D<float>(temp, 0, 0), 0)) {
			x -= movementPS * static_cast<GLfloat>(deltaTime);
		}
	}
	if(input->IsKeyDown(SDLK_d)) {
		float temp = x + movementPS * static_cast<GLfloat>(deltaTime);
		if(!CheckCollision(Vector3D<float>(temp, 0, 0), 1)) {
			x += movementPS * static_cast<GLfloat>(deltaTime);
		}
	}
	if(input->IsKeyDown(SDLK_w)) {
		float temp = y + movementPS * static_cast<GLfloat>(deltaTime);
		if(!CheckCollision(Vector3D<float>(0, temp, 0), 2)) {
			y += movementPS * static_cast<GLfloat>(deltaTime);
		}
	}
	if(input->IsKeyDown(SDLK_s)) {
		float temp = y - movementPS * static_cast<GLfloat>(deltaTime);
		if(!CheckCollision(Vector3D<float>(0, temp, 0), 3)) {
			y -= movementPS * static_cast<GLfloat>(deltaTime);
		}
	}

	//std::cout << "Ship (" << x << ", " << y << ", " << z << ")" << endl;
}

/**
Check if it is outside of frustrum
*/
bool Spaceship::CheckCollision(Vector3D<float> checkCol, int side) {
	if((checkCol.X() + colBox.X() * 2) >= 1 && side == 1) return true;
	if((checkCol.X() - colBox.X() * 2) <= -1 && side == 0) return true;
	if((checkCol.Y() + colBox.Y() * 3) >= 1 && side == 2) return true;
	if((checkCol.Y() - colBox.Y() * 3) <= -1 && side == 3) return true;
	if((checkCol.Z() + colBox.Z() * 2) <= 0 && side == 4) return true;
	if((checkCol.Z() - colBox.Z() * 2) >= -50 && side == 5) return true;
	return false;
}

bool Spaceship::CheckCollision(BaseShip *otShip) {
	return false;
}

Spaceship::~Spaceship() {
	bulletpool = NULL;
	input = NULL;
}