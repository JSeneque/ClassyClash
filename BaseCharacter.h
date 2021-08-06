#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter {
public:
    BaseCharacter();
    Vector2 getWorldPosition() { return worldPos;}
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void update(float deltaTime);
    virtual Vector2 getScreenPos() = 0;
protected:
    Texture2D texture {LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle {LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run {LoadTexture("characters/knight_run_spritesheet.png")};
    //Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame {};
    // 1 = facing right, -1 = facing left
    float rightLeft {1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.0f/12.0f}; // update 12 times a second
    float speed {4.0f};
    float width{};
    float height{};
    float scale {4.0f};
    Vector2 velocity{};
private:

};

#endif