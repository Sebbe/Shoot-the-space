#include "Bullet.h"

Bullet::Bullet(GLfloat shipX, GLfloat shipY, GLfloat shipZ) {
	x = shipX;
	y = shipY;
	z = shipZ;
	movementPS = 0.3;

	vertices[0] = -0.5f;
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

	// top right
	
	vertices[9] = 0.5f;
	vertices[10] = 0.5f;
	vertices[11] = 0.0f;
	std::cout << "Fuck this ";
}

void Bullet::Render() {
	glPushMatrix();
		glTranslatef(x, y, 0.0);
		glScalef(0.1, 0.1, 0.0);
		glColor3f(0.0f, 1.0f, 0.0f);
		glEnableClientState(GL_VERTEX_ARRAY);    // enable vertex arrays
		glVertexPointer(3, GL_FLOAT, 0, vertices);     // sette vertex pointer
		glDrawArrays (GL_TRIANGLES, 0, 3);                  // tegne 1 trekant
		glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays      
	glPopMatrix();
}

void Bullet::Update(double deltaTime) {
	y += (movementPS * static_cast<GLfloat>(deltaTime));
}

bool Bullet::Delete() {
	if(y >= 1.0f) return true;

	return false;
}

Bullet::~Bullet() {
	for(int i = 0; i > 12; i++) {
		vertices[i] = 0.0f;
	}
}