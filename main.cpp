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
    Vector2 knightPos {
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
        (float)windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
    };

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

        }
        
        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // draw the character
        Rectangle source{0.0f, 0.0f, (float)knight.width/6.0f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width /6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.0f, WHITE);


        EndDrawing();
    }
    CloseWindow();



    return 0;
}