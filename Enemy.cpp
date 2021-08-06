#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run =run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}

void Enemy::update(float deltaTime)
{
    // Get the direction to the target
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
    // normalise this direction
    toTarget = Vector2Normalize(toTarget);
    // Multiple by speed
    toTarget = Vector2Scale(toTarget, speed);
    // Move towards the target
    worldPos = Vector2Add(worldPos, toTarget);

    screenPos = Vector2Subtract(worldPos, target->getWorldPosition());


    BaseCharacter::update(deltaTime);

}
