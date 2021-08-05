#include "raylib.h"

class Enemy {
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    Vector2 getWorldPosition() { return worldPos;}
    void update(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();
private:
    Vector2 screenPos{};
    Vector2 worldPos{};
    Texture2D texture {LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle {LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run {LoadTexture("characters/knight_run_spritesheet.png")};    
    Vector2 worldPosLastFrame {};
    // 1 = facing right, -1 = facing left
    float rightLeft {1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.0f/12.0f}; // update 12 times a second
    const float speed {4.0f};
    float width{};
    float height{};
    float scale {4.0f};
};
