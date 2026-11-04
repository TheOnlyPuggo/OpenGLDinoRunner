#include "dino_runner/dino.h"

#include <iostream>

Dino::Dino(Game* game, float floorHeight)
    : GameObject(game, "textures/dino.png", true), FloorHeight(floorHeight)
{

}

void Dino::Update(float dt)
{
    GameObject::Update(dt);

    if (IsDead)
        return;

    if (!Grounded)
    {
        Velocity.y += Gravity * dt;
    }

    Position += Velocity * dt;

    if (Position.y + Size.y / 2.0f > FloorHeight)
    {
        Grounded = true;
        Velocity.y = 0.0f;
        Position.y = FloorHeight - Size.y / 2.0f;
    }
}

void Dino::Jump()
{
    if (!Grounded)
        return;

    Velocity.y -= JumpForce;
    Grounded = false;
}

void Dino::Kill()
{
    IsDead = true;
}

void Dino::Restart()
{
    IsDead = false;
    Velocity = glm::vec2(0.0f, 0.0f);
}
