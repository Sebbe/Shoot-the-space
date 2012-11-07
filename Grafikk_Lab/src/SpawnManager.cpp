#include <time.h>
#include "SpawnManager.h"
#include "GameManager.h"
#include "Ship\BaseShip.h"
#include "Ship\SimpleEnemy.h"
#include "Ship\AdvancedEnemy.h"
#include "Bulletpool.h"

SpawnManager::SpawnManager()
{
	maxEnemies = 20;
}

SpawnManager::SpawnManager(int maxEne)
{
	maxEnemies = maxEne;
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
	randomSpawnTime = 1;
	randomSpawnTimeAdvanced = 20;
	spawnTimer = 0;
	spawnTimerAdvanced = 0;

	for(int i = 0; i < maxEnemies; ++i)
	{
		BaseShip *temp = new SimpleEnemy(Vector3D<float>::Zero());
		temp->SetType(CollisionBox::CollisionTypes::ENEMY_SHIP);
		enemies.push_back(temp);

		BaseShip *tempAd = new AdvancedEnemy(Vector3D<float>::Zero());
		tempAd->SetType(CollisionBox::CollisionTypes::ENEMY_SHIP);
		tempAd->SetBulletpool(bulletpool);
		enemiesAdvanced.push_back(tempAd);
	}
}

void SpawnManager::SetMaxEnemies(int maxEnemies) {
	this->maxEnemies = maxEnemies;
}

void SpawnManager::Update(float deltaTime)
{
	spawnTimer += deltaTime;
	spawnTimerAdvanced += deltaTime;
	
	if(spawnTimer >= randomSpawnTime)
	{
 		Spawn();
		spawnTimer = 0;
		randomSpawnTime = GenerateRandomFloat(3.0f, 1.0f, false);
	}

	if(spawnTimerAdvanced >= randomSpawnTimeAdvanced)
	{
 		SpawnAdvanced();
		spawnTimerAdvanced = 0;
		randomSpawnTimeAdvanced = GenerateRandomFloat(10.0f, 8.0f, false);
	}

	for(unsigned int i = 0; i < enemies.size(); ++i)
	{
		if(enemies[i]->IsActive()) {
			enemies[i]->Update(deltaTime);
			if(enemies[i]->Delete()) {
				
			}
		}

		if(enemiesAdvanced[i]->IsActive()) {
			enemiesAdvanced[i]->Update(deltaTime);
			if(enemiesAdvanced[i]->Delete()) {
				
			}
		}
	}
}

void SpawnManager::Render()
{
	for(unsigned int i = 0; i < enemies.size(); ++i)
	{
		if(enemies[i]->IsActive()) {	
			enemies[i]->Render();
		}
		if(enemiesAdvanced[i]->IsActive()) {
			enemiesAdvanced[i]->Render();
		}
	}
}

void SpawnManager::Spawn()
{
	float x = GenerateRandomFloat(0.9, -0.9, true);
	float y = GenerateRandomFloat(0.9, -0.9, true);
	float z = -GameManager::ZFAR;
	Vector3D<float> pos(x,y,z);

	for(unsigned int i = 0; i < enemies.size(); ++i)
	{
		if(!enemies[i]->IsActive())
		{
			enemies[i]->Active(true);
			enemies[i]->SetPosition(pos);
			GameManager::collisionManager.AddCollideable(enemies[i]);
			return;
		}
	}
}

void SpawnManager::SpawnAdvanced()
{
	float x = GenerateRandomFloat(0.9, -0.9, true);
	float y = GenerateRandomFloat(0.9, -0.9, true);
	float z = -GameManager::ZFAR;
	Vector3D<float> pos(x,y,z);

	for(unsigned int i = 0; i < enemiesAdvanced.size(); ++i)
	{
		if(!enemiesAdvanced[i]->IsActive())
		{
			enemiesAdvanced[i]->Active(true);
			enemiesAdvanced[i]->SetPosition(pos);
			GameManager::collisionManager.AddCollideable(enemiesAdvanced[i]);
			return;
		}
	}
}

void SpawnManager::SetBulletpool(Bulletpool *manager) {
	bulletpool = manager;
}