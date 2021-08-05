#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    const int windowWidth {384};
    const int windowHeight {384};

    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("Tileset/map.png");
    Vector2 mapPos{0.0, 0.0};

    const float mapScale {4.0f};

    Character knight(windowWidth, windowHeight);

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPosition(), -1.0f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // check map bounds
        knight.update(GetFrameTime());
        
        if (knight.getWorldPosition().x < 0.0f ||
            knight.getWorldPosition().y < 0.0f ||
            knight.getWorldPosition().x + windowWidth > map.width * mapScale ||
            knight.getWorldPosition().y + windowHeight > map.height * mapScale )
            {
                knight.undoMovement();
            }

        EndDrawing();
    }
    CloseWindow();



    return 0;
}