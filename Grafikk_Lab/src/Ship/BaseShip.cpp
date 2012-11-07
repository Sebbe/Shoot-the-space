#include "ship/BaseShip.h"

BaseShip::BaseShip(Vector3D<float> position) {
	pos = position;
	active = false;
}


void BaseShip::Update(float deltaTime) {
	pos.SetZ(pos.Z() - movementPS * deltaTime);
}

Vector3D<float> BaseShip::getColBox() {
	return Vector3D<float>(colBox.X(), colBox.Y(), colBox.Z());
}

bool BaseShip::CheckCollision(Vector3D<float> checkCol, int side) {
	return false;
}

bool BaseShip::IsActive() {
	return active;
}

BaseShip::~BaseShip() {

}

CollisionBox* BaseShip::GetCollisionBox()
{
	return &_collisionBox;
}

void BaseShip::Collision(CollisionBox* other)
{

}

void BaseShip::SetType(CollisionBox::CollisionTypes type)
{
	_collisionBox.SetType(type);
}

bool BaseShip::Delete() {
	return false;
}

bool BaseShip::GetLifeLeft() {
	return iLife;
}

void BaseShip::SetLifeLeft(int life) {
	iLife = life;
}

void BaseShip::AddLifeLeft(int life) {
	iLife += life;
}

void BaseShip::DecresLifeLeft(int life) {
	iLife -= life;
}