#include "ship/AdvancedEnemy.h"
#include <GL/GL.h>
#include "GameManager.h"

AdvancedEnemy::AdvancedEnemy(Vector3D<float> position) : BaseShip(position) {
	movementPS = -2.0f;
	colBox.SetX(0.1);
	colBox.SetY(0.05);
	colBox.SetZ(0.1);
	_collisionBox = CollisionBox(&pos, colBox);
	SetLifeLeft(2);
	shootTimer = 0;
	nextShoot = GenerateRandomFloat(10, 5);
}

void AdvancedEnemy::Move() {

}

void AdvancedEnemy::Render() {
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
		glScalef(colBox.X(), colBox.Y(), colBox.Z());
		glColor3f(0.0f, 1.0f, 0.0f);
		glRotatef(90, 1, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);    // enable vertex arrays
		glVertexPointer(3, GL_FLOAT, 0, vertices);     // sette vertex pointer
		glDrawArrays (GL_TRIANGLES, 0, 30); // tegne 1 trekant
		glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
	glPopMatrix();
}

void AdvancedEnemy::Shoot() {
	if(nextShoot <= shootTimer) {
		bulletpool->AddBullet(pos.X(), pos.Y(), pos.Z(), CollisionBox::CollisionTypes::ENEMY_BULLET);
		nextShoot = GenerateRandomFloat(10, 5);
		shootTimer = 0;
	}
}

bool AdvancedEnemy::Delete() {
	if(pos.Z() >= GameManager::ZNEAR || iLife == 0)  {
		Active(false);
		return true;
	}
	return false;
}

bool AdvancedEnemy::CheckCollision(Vector3D<float> checkCol, int side) {
	if((checkCol.X() + colBox.X() * 2) >= 1 && side == 1) return true;
	if((checkCol.X() - colBox.X() * 2) <= -1 && side == 0) return true;
	if((checkCol.Y() + colBox.Y() * 3) >= 1 && side == 2) return true;
	if((checkCol.Y() - colBox.Y() * 3) <= -1 && side == 3) return true;
	if(checkCol.Z() >= 0 && side == 4) return true;
	if(checkCol.Z() <= -50 && side == 5) return true;
	return false;
}

void AdvancedEnemy::Update(float deltaTime) {
	BaseShip::Update(deltaTime);
	shootTimer += deltaTime;
	Shoot();
}

CollisionBox* AdvancedEnemy::GetCollisionBox()
{
	return &_collisionBox;
}


void AdvancedEnemy::Collision(CollisionBox* other)
{
	if(other->GetType() == CollisionBox::PLAYER_BULLET)
	{
		pos.SetZ(100.0);
		iLife--;
	}
	if(other->GetType() == CollisionBox::ENEMY_SHIP
		&& _collisionBox.GetType() == CollisionBox::ENEMY_BULLET)
	{
		return;
	}
}

void AdvancedEnemy::Active(bool isActive) {
	if(!isActive) {
		GameManager::collisionManager.RemoveCollideable(this);
		active = isActive;
		return;
	}
	_shouldDeActivate = false;
	active = isActive;
}

bool AdvancedEnemy::ShouldDeActivate() {
	return _shouldDeActivate;
}

void AdvancedEnemy::SetBulletpool(Bulletpool *manager) {
	bulletpool = manager;
}