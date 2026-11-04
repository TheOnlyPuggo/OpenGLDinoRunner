#ifndef DINORUNNER_GAME_OBJECT_H
#define DINORUNNER_GAME_OBJECT_H

#include "game.h"
#include "glm/detail/type_vec2.hpp"
#include "util/sprite_renderer.h"

class GameObject
{
private:
    static inline int ObjectIDTracker;

    int ID;
    SpriteRenderer* Renderer;

public:
    glm::vec2 Position;
    glm::vec2 Size;

    explicit GameObject(const Game* game, const std::string& texturePath, bool textureAlpha);
    virtual ~GameObject();

    virtual void Update(float dt);
    virtual void Draw() const;
};

#endif //DINORUNNER_GAME_OBJECT_H
