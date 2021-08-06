#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        getScreenPos().x, 
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void BaseCharacter::update(float deltaTime)
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

    if (Vector2Length(velocity) != 0.0)
    {
        
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
        
        texture = run;
    }
    else
    {
        texture = idle;
    }

    velocity = {};

    // draw the character
    Rectangle source{width * frame, 0.0f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}