#include "dino_runner/obstacle_spawner.h"

#include <iostream>

#include "dino_runner/obstacle.h"
#include "util/random_num.h"

ObstacleSpawner::ObstacleSpawner(class Dino* dino)
    : Dino(dino)
{
    CactusSpawnTime = RandomNum::getRandomFloat(CactusSpawnIntervalMin, CactusSpawnIntervalMax);
}

ObstacleSpawner::~ObstacleSpawner()
{
    for (std::size_t i = SpawnedObjects.size(); i-- > 0; )
    {
        delete SpawnedObjects[i];
        SpawnedObjects.pop_back();
    }
}

void ObstacleSpawner::Update(Game* game, float dt)
{
    CactusTimer += dt;

    if (CactusTimer >= CactusSpawnTime)
    {
        CactusTimer = 0.0f;
        CactusSpawnTime = RandomNum::getRandomFloat(CactusSpawnIntervalMin, CactusSpawnIntervalMax);

        auto* NewCactus = new Obstacle(game, Dino);
        SpawnedObjects.push_back(NewCactus);
    }

    for (auto SpawnedObject : SpawnedObjects)
    {
        SpawnedObject->Update(dt);

    }

    for (std::size_t i = 0; i < SpawnedObjects.size(); ++i)
    {
        SpawnedObjects[i]->Update(dt);

        if (SpawnedObjects[i]->Position.x < -30.0f)
        {
            delete SpawnedObjects[i];

            if (SpawnedObjects.size() > 1)
                SpawnedObjects[i] = SpawnedObjects[SpawnedObjects.size() - 1];

            SpawnedObjects.pop_back();
        }
    }
}

void ObstacleSpawner::DrawObstacles() const
{
    for (const auto SpawnedObject : SpawnedObjects)
    {
        SpawnedObject->Draw();
    }
}

void ObstacleSpawner::Restart()
{
    for (std::size_t i = SpawnedObjects.size(); i-- > 0; )
    {
        delete SpawnedObjects[i];
        SpawnedObjects.pop_back();
    }

    CactusTimer = 0.0f;
    CactusSpawnTime = RandomNum::getRandomFloat(CactusSpawnIntervalMin, CactusSpawnIntervalMax);
}
