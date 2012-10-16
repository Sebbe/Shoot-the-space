#include "Bullet.h"

Bullet::Bullet(GLfloat shipX, GLfloat shipY, GLfloat shipZ) {
	x = shipX;
	y = shipY;
	z = shipZ;
	movementPS = 2.3;

	rotQube = 0.0f;

	//Top
	// top right
	vertices[0] = 1.0f;
	vertices[1] = 1.0f;
	vertices[2] = -1.0f;
	//vertex 2 (top left)
	vertices[3] = -1.0f;
	vertices[4] = 1.0f;
	vertices[5] = -1.0f;
	//vertex 3 (bottom left)
	vertices[6] = -1.0f;
	vertices[7] = 1.0f;
	vertices[8] = 1.0f;
	//vertex 3 (bottom right)
	vertices[9] = 1.0f;
	vertices[10] = 1.0f;
	vertices[11] = 1.0f;

		  /*glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Top)
			glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Top)
			glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Quad (Top)
			glVertex3f( 1.0f, 1.0f, 1.0f);	// Bottom Right Of The Quad (Top)*/

	//bottom
	// top right
	vertices[12] = 1.0f;
	vertices[13] = -1.0f;
	vertices[14] = 1.0f;
	//vertex 2 (top left)
	vertices[15] = -1.0f;
	vertices[16] = -1.0f;
	vertices[17] = 1.0f;
	//vertex 3 (bottom left)
	vertices[18] = -1.0f;
	vertices[19] = -1.0f;
	vertices[20] = -1.0f;
	//vertex 3 (bottom right)
	vertices[21] = 1.0f;
	vertices[22] = -1.0f;
	vertices[23] = -1.0f;

	/*glVertex3f( 1.0f,-1.0f, 1.0f);	// Top Right Of The Quad (Bottom)
			glVertex3f(-1.0f,-1.0f, 1.0f);	// Top Left Of The Quad (Bottom)
			glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Bottom)
			glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Bottom)*/

	//front
	// top right
	vertices[24] = 1.0f;
	vertices[25] = 1.0f;
	vertices[26] = 1.0f;
	//vertex 2 (top left)
	vertices[27] = -1.0f;
	vertices[28] = 1.0f;
	vertices[29] = 1.0f;
	//vertex 3 (bottom left)
	vertices[30] = -1.0f;
	vertices[31] = -1.0f;
	vertices[32] = 1.0f;
	//vertex 3 (bottom right)
	vertices[33] = 1.0f;
	vertices[34] = -1.0f;
	vertices[35] = 1.0f;

	/*glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Front)
			glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Front)
			glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Front)
			glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Front)*/

	//back
	// top right
	vertices[36] = 1.0f;
	vertices[37] = -1.0f;
	vertices[38] = -1.0f;
	//vertex 2 (top left)
	vertices[39] = -1.0f;
	vertices[40] = -1.0f;
	vertices[41] = -1.0f;
	//vertex 3 (bottom left)
	vertices[42] = -1.0f;
	vertices[43] = 1.0f;
	vertices[44] = -1.0f;
	//vertex 3 (bottom right)
	vertices[45] = 1.0f;
	vertices[46] = 1.0f;
	vertices[47] = -1.0f;

	/*glVertex3f( 1.0f,-1.0f,-1.0f);	// Top Right Of The Quad (Back)
			glVertex3f(-1.0f,-1.0f,-1.0f);	// Top Left Of The Quad (Back)
			glVertex3f(-1.0f, 1.0f,-1.0f);	// Bottom Left Of The Quad (Back)
			glVertex3f( 1.0f, 1.0f,-1.0f);	// Bottom Right Of The Quad (Back)*/

	//left
	// top right
	vertices[48] = -1.0f;
	vertices[49] = 1.0f;
	vertices[50] = 1.0f;
	//vertex 2 (top left)
	vertices[51] = -1.0f;
	vertices[52] = 1.0f;
	vertices[53] = -1.0f;
	//vertex 3 (bottom left)
	vertices[54] = -1.0f;
	vertices[55] = -1.0f;
	vertices[56] = -1.0f;
	//vertex 3 (bottom right)
	vertices[57] = -1.0f;
	vertices[58] = -1.0f;
	vertices[59] = 1.0f;

	/*glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Left)
			glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Left)*/
	//right
	// top right
	vertices[60] = 1.0f;
	vertices[61] = 1.0f;
	vertices[62] = -1.0f;
	//vertex 2 (top left)
	vertices[63] = 1.0f;
	vertices[64] = 1.0f;
	vertices[65] = 1.0f;
	//vertex 3 (bottom left)
	vertices[66] = 1.0f;
	vertices[67] = -1.0f;
	vertices[68] = 1.0f;
	//vertex 3 (bottom right)
	vertices[69] = 1.0f;
	vertices[70] = -1.0f;
	vertices[71] = -1.0f;
}

void Bullet::setX(GLfloat x) {
	this->x = x;
}

void Bullet::setY(GLfloat y) {
	this->y = y;
}

void Bullet::setZ(GLfloat z) {
	this->z = z;
}

void Bullet::Render() {
	/*
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(rotQube, 1, 1, 1);
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

	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(rotQube, 1, 1, 1);
		glScalef(0.01, 0.01, 0.01);
		glColor3f(1.0f, 0.0f, 0.0f);
		glEnableClientState(GL_VERTEX_ARRAY);    // enable vertex arrays
		glVertexPointer(3, GL_FLOAT, 0, vertices);     // sette vertex pointer

		glColor3f(1.0f, 0.0f, 0.0f);
		glDrawArrays (GL_QUADS, 0, 4);
		glColor3f(1.0f, 1.0f, 0.0f);
		glDrawArrays (GL_QUADS, 4, 4);
		glColor3f(1.0f, 1.0f, 1.0f);
		glDrawArrays (GL_QUADS, (2 * 4), 4);
		glColor3f(0.0f, 1.0f, 0.0f);
		glDrawArrays (GL_QUADS, (3 * 4), 4);
		glColor3f(0.0f, 1.0f, 1.0f);
		glDrawArrays (GL_QUADS, (4 * 4), 4);
		glColor3f(0.0f, 0.0f, 1.0f);
		glDrawArrays (GL_QUADS, (5 * 4), 4);
		glColor3f(1.0f, 0.0f, 0.0f);
		/*for(int i = 0; i < 6; i++) {
			glColor3f(1.0f - (i / 10), (i / 5), 0.0f);
			glDrawArrays (GL_QUADS, (i * 4), 4);
		}*/
		glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
	glPopMatrix();
}

void Bullet::Update(double deltaTime) {
	//y += (movementPS * static_cast<GLfloat>(deltaTime));
	z -= (movementPS * static_cast<GLfloat>(deltaTime));
	//std::cout << "bullet (" << x << ", " << y << ", " << z << ")" << endl;
	//rotQube += 90.0f*static_cast<float>(deltaTime);
	if (rotQube >= 360) {
		rotQube -= 360;
	}
}

bool Bullet::Delete() {
	if(z <= -25.0f) return true;

	return false;
}

Bullet::~Bullet() {

}
