#include "game.h"

#include <iostream>

#include "dino_runner/dino.h"
#include "dino_runner/game_object.h"
#include "dino_runner/obstacle.h"
#include "dino_runner/obstacle_spawner.h"
#include "GLFW/glfw3.h"
#include "glm/gtc/matrix_transform.hpp"
#include "util/resource_manager.h"
#include "util/sprite_renderer.h"

GameObject* Floor;
Dino* Dino;
GameObject* GameOverText;

ObstacleSpawner* ObstacleSpawner;

Game::Game(unsigned int width, unsigned int height)
    : State(GameActive), Keys(), Width(width), Height(height)
{
    State = GameActive;
    FloorHeight = static_cast<float>(Height) * 0.66f;
}

Game::~Game()
{
    delete Dino;
}

void Game::Init()
{
    Floor = new GameObject(this, "textures/line.png", true);
    Floor->Position = glm::vec2(400.0f, 392.0f);
    Floor->Size = glm::vec2(1000.0f, 5.0f);

    Dino = new class Dino(this, FloorHeight);
    Dino->Position = glm::vec2(100.0f, 300.0f);
    Dino->Size = glm::vec2(90.0f, 90.0f);

    GameOverText = new GameObject(this, "textures/gameover.png", true);
    GameOverText->Position = glm::vec2(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) / 3.0f);
    GameOverText->Size = glm::vec2(345.0f, 45.0f);

    ObstacleSpawner = new class ObstacleSpawner(Dino);
}

void Game::ProcessInput(float dt)
{
    if (State == GameActive)
    {
        if (Keys[GLFW_KEY_SPACE] || Keys[GLFW_KEY_UP] || Keys[GLFW_KEY_W])
        {
            Dino->Jump();
        }
    }
    else if (State == GameOver)
    {
        if (Keys[GLFW_KEY_R])
        {
            Dino->Restart();
            ObstacleSpawner->Restart();
            Obstacle::UniversalSpeed = Obstacle::InitialUniversalSpeed;
            State = GameActive;
        }
    }
}

void Game::Update(float dt)
{
    if (State == GameActive)
    {
        if (Dino->IsDead)
        {
            Obstacle::UniversalSpeed = 0.0f;
            State = GameOver;
        }

        Dino->Update(dt);

        ObstacleSpawner->Update(this, dt);
    }
}

void Game::Render()
{
    Floor->Draw();
    Dino->Draw();

    ObstacleSpawner->DrawObstacles();

    if (State == GameOver)
    {
        GameOverText->Draw();
    }
}
