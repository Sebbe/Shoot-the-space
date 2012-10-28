#include <time.h>
#include "SpawnManager.h"
#include "GameManager.h"
#include "Ship\BaseShip.h"
#include "Ship\SimpleEnemy.h"
#include "Bulletpool.h"

SpawnManager::SpawnManager()
{
	maxEnemies = 20;
	randomSpawnTime = 1;
	spawnTimer = 0;
}

SpawnManager::SpawnManager(int maxEne)
{
	maxEnemies = maxEne;
	randomSpawnTime = 1;
	spawnTimer = 0;
}

SpawnManager::~SpawnManager()
{
	while(!enemies.empty())
	{
		delete enemies.back();
		enemies.pop_back();
	}
}

void SpawnManager::Init()
{
	for(int i = 0; i < maxEnemies; ++i)
	{
		enemies.push_back(new SimpleEnemy(
			Vector3D<float>::Zero()));
	}
}

void SpawnManager::SetMaxEnemies(int maxEnemies) {
	this->maxEnemies = maxEnemies;
}

void SpawnManager::Update(float deltaTime)
{
	spawnTimer += deltaTime;
	
	for(int i = 0; i < Bulletpool::activeBullets.size(); i++) {
		if(Bulletpool::activeBullets[i] == true) {
			for(int j = 0; j < enemies.size(); ++j) {
				if(enemies[j]->IsActive()) {
					enemies[j]->CheckCollision(Bulletpool::bulletList[i]);
				}
			}
		}
	}

	if(spawnTimer >= randomSpawnTime)
	{
 		Spawn();
		spawnTimer = 0;
		randomSpawnTime = GenerateRandomFloat(3.0f, 1.0f, false);
	}

	for(unsigned int i = 0; i < enemies.size(); ++i)
	{
		enemies[i]->Update(deltaTime);
	}
}

void SpawnManager::Render()
{
	for(unsigned int i = 0; i < enemies.size(); ++i)
	{
		enemies[i]->Render();
	}
}

void SpawnManager::Spawn()
{
	float x = GenerateRandomFloat(1, -1, true);
	float y = GenerateRandomFloat(1, -1, true);
	float z = -GameManager::ZFAR;
	Vector3D<float> pos(x,y,z);

	for(unsigned int i = 0; i < enemies.size(); ++i)
	{
		if(!enemies[i]->IsActive())
		{
			enemies[i]->Active(true);
			enemies[i]->SetPosition(pos);
			return;
		}
	}
}