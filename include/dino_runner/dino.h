#ifndef DINORUNNER_DINO_H
#define DINORUNNER_DINO_H
#include "game_object.h"

class Dino : public GameObject
{
private:
    float FloorHeight;

    glm::vec2 Velocity = glm::vec2(0.0f, 0.0f);
    bool Grounded = false;
    float Gravity = 1400.0f;
    float JumpForce = 500.0f;

public:
    bool IsDead = false;

    explicit Dino(Game* game, float floorHeight);

    void Update(float dt) override;

    void Jump();
    void Kill();
    void Restart();
};

#endif //DINORUNNER_DINO_H
