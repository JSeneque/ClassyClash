#include "raylib.h"
int main()
{
    const int windowWidth {640};
    const int windowHeight {380};

    InitWindow(windowWidth, windowHeight, "Classy Clash");
    Texture2D map = LoadTexture("./Tileset/map.png");

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
    CloseWindow();



    return 0;
}