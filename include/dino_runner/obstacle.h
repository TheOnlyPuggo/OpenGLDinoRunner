#ifndef DINORUNNER_OBSTACLE_H
#define DINORUNNER_OBSTACLE_H

#include "dino.h"
#include "game_object.h"

class Obstacle : public GameObject
{
private:
    Dino* Dino;

public:
    static inline float InitialUniversalSpeed = 250.0f;
    static inline float UniversalSpeed = InitialUniversalSpeed;

    explicit Obstacle(Game* game, class Dino* dino);

    void Update(float dt) override;
};

#endif
