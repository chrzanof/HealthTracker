#include <iostream>
#include <fstream>
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "json.hpp"

int main()
{
    std::ifstream jsonFile = std::ifstream("profiles/profile1.json");
    nlohmann::json profile1 = nlohmann::json::parse(jsonFile);
    jsonFile.close();
    std::string profileName = profile1["profile"];
    std::string gender = profile1["gender"];
    float height = profile1["height"];
    int age = profile1["age"];
    std::cout << "profile: " << profileName << std::endl;
    std::cout << "gender: " << gender << std::endl;
    std::cout << "height: " << height << std::endl;
    std::cout << "age: " << age << std::endl;


    
    InitWindow(400, 200, "raygui - controls test suite");
    SetTargetFPS(60);

    bool showMessageBox = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        Rectangle buttonBounds = { 24, 24, 120, 30 };
        if (GuiButton(buttonBounds, "#191#Show Message")) showMessageBox = true;

        

        if (showMessageBox)
        {
            Rectangle msgBoxBounds = { 85, 70, 250, 100 };
            int result = GuiMessageBox(Rectangle{ 85, 70, 250, 100 }, "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

            if (result >= 0) showMessageBox = false;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
