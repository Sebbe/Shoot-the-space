#include "ship/AdvancedEnemy.h"
#include <GL/GL.h>

AdvancedEnemy::AdvancedEnemy(Vector3D<float> position) : BaseShip(position) {
	movementPS = -10.0f;
}