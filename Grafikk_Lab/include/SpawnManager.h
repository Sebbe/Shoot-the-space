#ifndef SPAWN_MANAGER_H
#define SPAWN_MANAGER_H

#include "Utils/Vector3D.h"
#include "Renderable.h"
#include <vector>
#include "Ship/BaseShip.h"
#include "Ship\SimpleEnemy.h"
#include "Bulletpool.h"

class SpawnManager : public Renderable
{
public:
	SpawnManager();
	SpawnManager(int nrOfEnemies);
	~SpawnManager();

	void Update(float deltaTime);
	void Render();
	void Spawn();
	void SpawnAdvanced();
	void Init();
	void SetMaxEnemies(int maxEnemies);
	void SetBulletpool(Bulletpool *manager);

	std::vector<BaseShip*> enemies;
	std::vector<BaseShip*> enemiesAdvanced;
	int maxEnemies;
	float spawnTimer;
	float spawnTimerAdvanced;
	float randomSpawnTime;
	float randomSpawnTimeAdvanced;

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

protected:
	Bulletpool *bulletpool;
};

#endif