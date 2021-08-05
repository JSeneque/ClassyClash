#include "Enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) :
worldPos(pos),
texture(idle_texture),
idle(idle_texture),
run(run_texture)
{
    width = texture.width / maxFrames;
    height = texture.height;
}

void Enemy::update(float deltaTime)
{
    worldPosLastFrame = worldPos;

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.0f;
        frame++;
        if (frame > maxFrames)
            frame = 0;
    }

    // draw the character
    Rectangle source{width * frame, 0.0f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

void Enemy::undoMovement()
{
    worldPos = worldPosLastFrame;
}
    
Rectangle Enemy::getCollisionRec()
{
    return Rectangle{
        screenPos.x, 
        screenPos.y,
        width * scale,
        height * scale
    };
}