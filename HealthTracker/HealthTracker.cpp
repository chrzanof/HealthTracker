#include "raylib.h"

int main(void)
{
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Health Tracker");

    SetTargetFPS(60);              

    while (!WindowShouldClose())   
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("Hello, Window!", 320, 200, 20, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}