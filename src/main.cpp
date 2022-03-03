#include <cstdlib>

#include "raylib.h"

#include "config.h"



int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

    Vector2 position;
    int movementSpeed;
    int framesCounter;
    int screenW;
    int screenH;

    typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } Gamescreen;
    

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    Texture2D myTexture = LoadTexture("assets/graphics/pixelRick.png");
    Texture2D secondTexture = LoadTexture("assets/graphics/testimage.png");

    position.x = 250;
    position.y = 150;
    movementSpeed = 5;
    framesCounter = 0;
    screenW = 960;
    screenH = 540;

    GameScreen currentScreen = LOGO;
    

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        
       
        //tracking if circle touches the edges of the screen
       /*
       if (position.x <= 960 || position.x >= 0)
        {
            position.x * -1;
        }
        */

        switch (currentScreen) {

            case LOGO:
            {
                //TO DO: update frames variables here

                framesCounter++;

                //wait 2 seconds (120 frames) before jumping to next frame
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(KEY_TAB))
                {
                    currentScreen = GAMEPLAY;
                }

            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(KEY_TAB))
                {
                    currentScreen = ENDING;
                }

                //press W A S D to move
                if (IsKeyDown(KEY_D))
                {
                    position.x += movementSpeed; //cirlce slowly goes right
                }
                else if (IsKeyDown(KEY_A))
                {
                    position.x -= movementSpeed; //circle goes left
                }
                else if (IsKeyDown(KEY_W))
                {
                    position.y -= movementSpeed; //circle goes up
                }
                else if (IsKeyDown(KEY_S))
                {
                    position.y += movementSpeed; //circle goes down
                }

            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }

            } break;
            default: break;

        }

      

        //collision mit bildschirmrand abfragen
        //wenn collision dann movement speed auf 0

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            
            switch (currentScreen)
            {

                case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenW, screenH, GREEN);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;
                case GAMEPLAY:
                {
                    //Draw Game Screen here
                    ClearBackground(RAYWHITE);
                    DrawText("Hello, world!", 10, 10, 30, SKYBLUE);
                    DrawTexture(myTexture, 10, 100, WHITE);
                    DrawTextureV(secondTexture, position, WHITE);
                    DrawText("I changed this!", 10, 350, 30, SKYBLUE);
                    DrawText("I added this for Github", 10, 400, 30, SKYBLUE);
                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenW, screenH, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
                } break;
                default: break;
            }

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
