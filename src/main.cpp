#include <cstdlib>

#include "raylib.h"

#include "config.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    Texture2D myTexture = LoadTexture("assets/graphics/pixelRick.png");
    Texture2D secondTexture = LoadTexture("assets/graphics/testimage.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(RAYWHITE);
            DrawText("Hello, world!", 10, 10, 30, SKYBLUE);
            DrawTexture(myTexture, 10, 100, WHITE);
            DrawTexture(secondTexture, 250, 150, WHITE);
            DrawText("I changed this!", 10, 350, 30, SKYBLUE);
            DrawText("I added this for Github", 10, 400, 30, SKYBLUE);

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
