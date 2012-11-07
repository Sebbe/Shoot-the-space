#include "Collision/CollisionBox.h"

CollisionBox::CollisionBox()
{
	SetPosition(NULL);
	SetBounds(Vector3D<float>::Zero());
	_type = NOT_IMPLEMENTED;
}

/**
 * Construter
 * Set position and bounds
 *
 */
CollisionBox::CollisionBox(Vector3D<float>* pos, Vector3D<float> bounds)
{
	SetPosition(pos);
	SetBounds(bounds);
	_type = NOT_IMPLEMENTED;
}

CollisionBox::~CollisionBox()
{

}

/**
 * Sets x y og z
 *
 */
void CollisionBox::Init()
{
	GLfloat x = _bounds.X();
	GLfloat y = _bounds.Y();
	GLfloat z = _bounds.Z();
}

/**
 * Sets position
 *
 */
void CollisionBox::SetPosition(Vector3D<float>* pos)
{
	_position = pos;
}

/**
 * Return position
 *
 */
Vector3D<float>* CollisionBox::GetPosition() const
{
	return _position;
}

/**
 * Sets bounds
 *
 */
void CollisionBox::SetBounds(Vector3D<float> bounds)
{
	_bounds = bounds;
}

/**
 * Return bounds
 *
 */
Vector3D<float> CollisionBox::GetBounds() const
{
	return _bounds;
}

/**
 * Checks if two collidables intersects with each other
 *
 */
bool CollisionBox::Intersects(const CollisionBox& other)
{
	Vector3D<float>* otherPos = other.GetPosition();
	Vector3D<float>& otherBounds = other.GetBounds();
	
	if( _LeftCollision(otherPos, otherBounds)
		&& _RightCollision(otherPos, otherBounds)
		&& _TopCollision(otherPos, otherBounds)
		&& _BottomCollision(otherPos, otherBounds)
		&& _FrontCollision(otherPos, otherBounds)
		&& _BackCollision(otherPos, otherBounds) )
	{
  		return true;
	}
	return false;
}

/**
 * Nothing to draw
 *
 */
void CollisionBox::Draw()
{
	
}

/**
 * Sets which type the collidable is
 *
 */
void CollisionBox::SetType(CollisionTypes type)
{
	_type = type;
}

/**
 * Rest of this functions just check the collision
 *
 */

bool CollisionBox::_LeftCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds)
{
	if(_position->X() - _bounds.X() < otherPos->X() + otherBounds.X())
	{
		return true;
	}
	return false;
}

bool CollisionBox::_RightCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds)
{
	if(_position->X() + _bounds.X() > otherPos->X() - otherBounds.X())
	{
		return true;
	}
	return false;
}

bool CollisionBox::_TopCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds)
{
	if(_position->Y() + _bounds.Y() > otherPos->Y() - otherBounds.Y())
	{
		return true;
	}
	return false;
}

bool CollisionBox::_BottomCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds)
{
	if(_position->Y() - _bounds.Y() < otherPos->Y() + otherBounds.Y())
	{
		return true;
	}
	return false;
}

bool CollisionBox::_FrontCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds)
{
	if(_position->Z() + _bounds.Z() > otherPos->Z() - otherBounds.Z())
	{
		return true;
	}
	return false;
}

bool CollisionBox::_BackCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds)
{
	if(_position->Z() - _bounds.Z() < otherPos->Z() + otherBounds.Z())
	{
		return true;
	}
	return false;
}