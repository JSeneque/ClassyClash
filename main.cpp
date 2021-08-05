#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    const int windowWidth {640};
    const int windowHeight {380};

    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("Tileset/map.png");
    Vector2 mapPos{0.0, 0.0};

    Character knight;
    knight.setScreenPosition(windowWidth, windowHeight);

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPosition(), -1.0f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        knight.update(GetFrameTime());

        EndDrawing();
    }
    CloseWindow();



    return 0;
}