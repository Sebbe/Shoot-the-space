#ifndef COLLISIONBOX_H__
#define COLLISIONBOX_H__

#include "Utils/Vector3D.h"
#include "Renderable.h"

class CollisionBox : public Renderable
{
public:
	enum CollisionTypes { 
		NOT_IMPLEMENTED, 
		PLAYER_BULLET,
		ENEMY_BULLET, 
		ENEMY_SHIP, 
		PLAYER_SHIP 
	};

public:
	/**
	 * Constructer and destructer
	 *
	 */
	CollisionBox();
	CollisionBox(Vector3D<float>* pos, Vector3D<float> bounds);
	~CollisionBox();

	/**
	 * Init function
	 *
	 */
	void Init();

	/**
	 * Sets position
	 *
	 */
	void SetPosition(Vector3D<float>* pos);
	Vector3D<float>* GetPosition() const;

	/**
	 * Bounds
	 *
	 */
	void SetBounds(Vector3D<float> bounds);
	Vector3D<float> GetBounds() const;

	/**
	 *
	 *
	 */
	bool Intersects(const CollisionBox& other);

	/**
	 *
	 *
	 */
	void Draw();

	/**
	 *
	 *
	 */
	void SetType(CollisionTypes type);

	/**
	 *
	 *
	 */
	inline CollisionTypes GetType() {return _type;}

private:
	// Main variables
	Vector3D<float>* _position;
	Vector3D<float> _bounds;
	CollisionTypes _type;

	// HELP FUNCTIONS
	bool _LeftCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds);
	bool _RightCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds);
	bool _TopCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds);
	bool _BottomCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds);
	bool _FrontCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds);
	bool _BackCollision(Vector3D<float>* otherPos, Vector3D<float>& otherBounds);
};

#endif