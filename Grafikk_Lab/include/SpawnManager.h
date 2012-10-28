#ifndef SPAWN_MANAGER_H
#define SPAWN_MANAGER_H

#include "Utils/Vector3D.h"
#include "Renderable.h"
#include <vector>
#include "Ship/BaseShip.h"
#include "Ship\SimpleEnemy.h"


class SpawnManager : public Renderable
{
public:
	SpawnManager();
	SpawnManager(int nrOfEnemies);
	~SpawnManager();

	void Update(float deltaTime);
	void Render();
	void Spawn();
	void Init();
	void SetMaxEnemies(int maxEnemies);

	std::vector<BaseShip*> enemies;
	int maxEnemies;
	float spawnTimer;
	float randomSpawnTime;

	float GenerateRandomFloat(float maxNum, float minNum, bool minNegative = false)
		{
			if(minNegative)
				maxNum *= 100 * 2;
			else
				maxNum *= 100;

			minNum *= 100;
			int maxInt = static_cast<int>(maxNum);
			return (static_cast<float>(rand() % maxInt) + minNum) / 100;
		}
};

#endif