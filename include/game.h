#ifndef DINORUNNER_GAME_H
#define DINORUNNER_GAME_H

enum GameState
{
    GameActive,
    GameOver
};

class Game
{
    GameState State;
    bool Keys[1024];
    unsigned int Width, Height;

    Game(unsigned int width, unsigned int height);
    ~Game();

    void Init();
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

#endif //DINORUNNER_GAME_H
