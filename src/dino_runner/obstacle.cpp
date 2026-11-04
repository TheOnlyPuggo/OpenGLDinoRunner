#include "dino_runner/obstacle.h"

#include <iostream>

Obstacle::Obstacle(Game* game, class Dino* dino) :
    GameObject(game, "textures/cactus1.png", true), Dino(dino)
{
    Size = glm::vec2(90.0f, 90.0f);
    Position.x = 1000.0f;
    Position.y = game->FloorHeight - Size.y / 2.0f - 7.0f;
}

void Obstacle::Update(float dt)
{
    GameObject::Update(dt);

    Position.x -= UniversalSpeed * dt;

    // Dino Collision Check
    if (
        ((Position.x + Size.x / 8.0f > Dino->Position.x - Size.x / 2.5f
        && Position.x + Size.x / 8.0f < Dino->Position.x + Size.x / 2.5f)
        ||
        (Position.x - Size.x / 8.0f < Dino->Position.x + Size.x / 2.5f
        && Position.x - Size.x / 8.0f > Dino->Position.x - Size.x / 2.5f))
        &&
        ((Position.y + Size.y / 8.0f > Dino->Position.y - Size.y / 2.5f
        && Position.y + Size.y / 8.0f < Dino->Position.y + Size.y / 2.5f)
        ||
        (Position.y - Size.y / 8.0f < Dino->Position.y + Size.y / 2.5f
        && Position.y - Size.y / 8.0f > Dino->Position.y - Size.y / 2.5f))
        )
    {
        Dino->Kill();
    }
}
