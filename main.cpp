#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

int main()
{
    const int windowWidth {384};
    const int windowHeight {384};

    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("Tileset/map.png");
    Vector2 mapPos{0.0, 0.0};

    const float mapScale {4.0f};

    Character knight(windowWidth, windowHeight);

    Prop props[2] {
        Prop {Vector2{300.0f, 300.0f}, LoadTexture("nature_tileset/Rock.png")},
        Prop {Vector2{400.0f, 500.0f}, LoadTexture("nature_tileset/Log.png")}
    };

    Enemy goblin {
        Vector2{},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")   
        };

    goblin.setTarget(&knight);

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPosition(), -1.0f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // draw the props
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPosition());

        }

        // check map bounds
        knight.update(GetFrameTime());
        
        if (knight.getWorldPosition().x < 0.0f ||
            knight.getWorldPosition().y < 0.0f ||
            knight.getWorldPosition().x + windowWidth > map.width * mapScale ||
            knight.getWorldPosition().y + windowHeight > map.height * mapScale )
            {
                knight.undoMovement();
            }

        // check for collisions
        for (auto prop : props)
        {
            if(CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPosition()), knight.getCollisionRec()))
            {
                knight.undoMovement();
            }
        }

        goblin.update(GetFrameTime());

        EndDrawing();
    }
    CloseWindow();



    return 0;
}