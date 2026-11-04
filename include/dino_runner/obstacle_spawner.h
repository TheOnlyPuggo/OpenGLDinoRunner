#ifndef DINORUNNER_OBSTACLE_SPAWNER_H
#define DINORUNNER_OBSTACLE_SPAWNER_H
#include <vector>

#include "dino.h"
#include "game.h"
#include "game_object.h"

class ObstacleSpawner
{
private:
    Dino* Dino;
    std::vector<GameObject*> SpawnedObjects{};

    float CactusSpawnIntervalMin = 0.5f;
    float CactusSpawnIntervalMax = 2.5f;
    float CactusTimer = 0.0f;
    float CactusSpawnTime;
public:
    ObstacleSpawner(class Dino* dino);
    ~ObstacleSpawner();

    void Update(Game* game, float dt);
    void DrawObstacles() const;
    void Restart();
};

#endif //DINORUNNER_OBSTACLE_SPAWNER_H
