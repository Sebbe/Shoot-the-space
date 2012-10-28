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

bool BaseShip::CheckCollision(BaseShip *otShip) {
	return false;
}

bool BaseShip::CheckCollision(Vector3D<float> checkCol, int side) {
	return false;
}

bool BaseShip::IsActive() {
	return active;
}

bool BaseShip::CheckCollision(Bullet *aBullet) {
	if(aBullet->getZ() == pos.Z()) {
		active = false;
		pos.SetZ(20);
		return true;
	}
}

BaseShip::~BaseShip() {

}