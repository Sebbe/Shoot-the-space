#ifndef BULLETPOOL_H
#define BULLETPOOL_H

#include <vector>
#include "Bullet.h"

class Bulletpool {
public:
	Bulletpool();
	int AddBullet(GLfloat shipX, GLfloat shipY, GLfloat shipZ);
	void RemoveBullet(int id);
	Bullet* GetBullet(int id);
	void Update(double deltaTime);
	void Render();
	static std::vector<Bullet*> bulletList;
	static std::vector<bool> activeBullets;
private:
	
	
	int maxBullets;
	int totalActiveBullets;
};

#endif