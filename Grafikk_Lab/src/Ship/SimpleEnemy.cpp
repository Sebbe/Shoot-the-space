#include "ship/SimpleEnemy.h"
#include <GL/GL.h>

SimpleEnemy::SimpleEnemy(Vector3D<float> position) : BaseShip(position) {
	movementPS = -10.0f;
}

void SimpleEnemy::Move() {

}

void SimpleEnemy::Render() {
	float x, y, z;
	x = y = 1.0f;
	z = 1.0f;
	GLfloat vertices[30][3] = {
		{-x,-y, z}, { 0,-y, z}, { 0, y, z}, // left half of front
		{ 0,-y, z}, { x,-y, z}, { 0, y, z}, // right half of front
		{ 0, y,-z}, { 0,-y,-z}, {-x,-y,-z}, // left half of back
		{ 0, y,-z}, { x,-y,-z}, { 0,-y,-z}, // right half of back
		{ 0, y, z}, { x,-y, z}, { x,-y,-z}, // left half of right side
		{ 0, y, z}, { x,-y,-z}, { 0, y,-z}, // right half of right side
		{ 0, y,-z}, {-x,-y,-z}, {-x,-y, z}, // left half of left side
		{ 0, y,-z}, {-x,-y, z}, { 0, y, z}, // right half of left side
		{-x,-y, z}, {-x,-y,-z}, { x,-y,-z}, // left side of bottom
		{-x,-y, z}, { x,-y,-z}, { x,-y, z}  // right side of bottom
	};
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(pos.X(), pos.Y(), pos.Z());
		glScalef(0.1, 0.1, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		glRotatef(90, 1, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);    // enable vertex arrays
		glVertexPointer(3, GL_FLOAT, 0, vertices);     // sette vertex pointer
		glDrawArrays (GL_TRIANGLES, 0, 30); // tegne 1 trekant
		glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
	glPopMatrix();
}

void SimpleEnemy::Shoot() {

}

bool SimpleEnemy::CheckCollision(BaseShip *otShip) {
	return false;
}

bool SimpleEnemy::CheckCollision(Vector3D<float> checkCol, int side) {
	if((checkCol.X() + colBox.X() * 2) >= 1 && side == 1) return true;
	if((checkCol.X() - colBox.X() * 2) <= -1 && side == 0) return true;
	if((checkCol.Y() + colBox.Y() * 3) >= 1 && side == 2) return true;
	if((checkCol.Y() - colBox.Y() * 3) <= -1 && side == 3) return true;
	if(checkCol.Z() >= 0 && side == 4) return true;
	if(checkCol.Z() <= -50 && side == 5) return true;
	return false;
}

bool SimpleEnemy::CheckCollision(Bullet *aBullet) {
	if(aBullet->getZ() == pos.Z()) {
		active = false;
		pos.SetZ(20);
		return true;
	}

	return false;
}

void SimpleEnemy::Update(float deltaTime) {
	BaseShip::Update(deltaTime);
	if(CheckCollision(pos, 4)) {
		active = false;
	}
}