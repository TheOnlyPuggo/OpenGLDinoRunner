#include "dino_runner/game_object.h"
#include "glm/gtc/matrix_transform.hpp"
#include "util/resource_manager.h"

GameObject::GameObject(const Game* game, const std::string& texturePath, const bool textureAlpha)
    : Position(0.0f, 0.0f)
{
    ID = ObjectIDTracker;
    ObjectIDTracker += 1;

    ResourceManager::LoadShader("shaders/sprite_vert.glsl", "shaders/sprite_frag.glsl", nullptr, "sprite");
    glm::mat4 projection =
        glm::ortho(0.0f, static_cast<float>(game->Width), static_cast<float>(game->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    ResourceManager::LoadTexture(texturePath.c_str(), textureAlpha, std::to_string(ID));

}

GameObject::~GameObject()
{
    delete Renderer;
}

void GameObject::Update(float dt)
{
}


void GameObject::Draw() const
{
    Renderer->DrawSprite(
        ResourceManager::GetTexture(std::to_string(ID)),
        glm::vec2(Position.x - Size.x / 2.0f, Position.y - Size.y / 2.0f),
        Size
        );
}
