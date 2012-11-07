#include "Bulletpool.h"
#include "GameManager.h"
std::vector<Bullet*> Bulletpool::bulletList;
std::vector<bool> Bulletpool::activeBullets;

Bulletpool::Bulletpool() {
	maxBullets = 100;
	totalActiveBullets = 0;
	for(int i = 0; i < maxBullets; i++) {
		Bullet *temp = new Bullet(-100, -100, 100);
		temp->SetType(CollisionBox::CollisionTypes::PLAYER_BULLET);
		bulletList.push_back(temp);
		activeBullets.push_back(false);
	}
}

int Bulletpool::AddBullet(GLfloat shipX, GLfloat shipY, GLfloat shipZ) {
	//finds next bullet in the list that is not in use and makes it active
	if(totalActiveBullets == (maxBullets - 1)) {
		//std::cout << "Bullet not added";
		return -1;
	}
	for(int i = 0; i < maxBullets; i++) {
		if(activeBullets[i] == false) {
			//std::cout << "Bullet added";
			activeBullets[i] = true;
			bulletList[i]->SetActive(true);
			bulletList[i]->setX(shipX);
			bulletList[i]->setY(shipY);
			bulletList[i]->setZ(shipZ);
			bulletList[i]->SetType(CollisionBox::CollisionTypes::PLAYER_BULLET);
			GameManager::collisionManager.AddCollideable(bulletList[i]);
			return i;
		}
	}
}

int Bulletpool::AddBullet(GLfloat shipX, GLfloat shipY, GLfloat shipZ, CollisionBox::CollisionTypes type) {
	//finds next bullet in the list that is not in use and makes it active
	if(totalActiveBullets == (maxBullets - 1)) {
		//std::cout << "Bullet not added";
		return -1;
	}
	for(int i = 0; i < maxBullets; i++) {
		if(activeBullets[i] == false) {
			//std::cout << "Bullet added";
			activeBullets[i] = true;
			bulletList[i]->SetActive(true);
			bulletList[i]->setX(shipX);
			bulletList[i]->setY(shipY);
			bulletList[i]->setZ(shipZ);
			bulletList[i]->SetType(type);
			GameManager::collisionManager.AddCollideable(bulletList[i]);
			return i;
		}
	}
}

void Bulletpool::Render() {
	for(std::size_t i = 0; i < activeBullets.size(); i++) {
		if(activeBullets[i] == true) {
			bulletList[i]->Render();
		}
	}
}

void Bulletpool::Update(double deltaTime) {
	for(std::size_t i = 0; i < activeBullets.size(); i++) {
		if(activeBullets[i] == true) {
			bulletList[i]->Update(deltaTime); 
			if(bulletList[i]->Delete()) {
				activeBullets[i] = false;
				bulletList[i]->setX(-1000);
				bulletList[i]->setY(-1000);
				bulletList[i]->setZ(-1000);
				totalActiveBullets--;
			}
		}
	}
}