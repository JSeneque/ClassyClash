#include "raylib.h"
#include "raymath.h"
int main()
{
    const int windowWidth {640};
    const int windowHeight {380};

    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("Tileset/map.png");
    Vector2 mapPos{0.0, 0.0};

    const float speed {4.0f};

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");

    Vector2 knightPos {
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
        (float)windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
    };

    // 1 = facing right, -1 = facing left
    float rightLeft {1.0f};

    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.0f/12.0f}; // update 12 times a second

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction {};

        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;

        if (Vector2Length(direction) != 0.0)
        {
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
            direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
            knight = knight_run;

        } else {
            knight = knight_idle;
        }
        
        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // update animation frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            runningTime = 0.0f;
            frame++;
            if(frame > maxFrames) frame = 0;
        }

        // draw the character
        Rectangle source{(float)knight.width/6.0f * frame , 0.0f,  rightLeft * (float)knight.width/6.0f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width /6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.0f, WHITE);


        EndDrawing();
    }
    CloseWindow();



    return 0;
}