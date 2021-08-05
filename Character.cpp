#include "Character.h"
#include "raymath.h"

Character::Character()
{
    width = texture.width / maxFrames;
    height = texture.height;
}

void Character::setScreenPosition(int windowWidth, int windowHeight)
{
    screenPos = {
        (float)windowWidth / 2.0f - 4.0f * (0.5f * width),
        (float)windowHeight / 2.0f - 4.0f * (0.5f * height)};
}

void Character::update(float deltaTime)
{
    Vector2 direction{};

    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;

    if (Vector2Length(direction) != 0.0)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

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
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * width, 4.0f * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}