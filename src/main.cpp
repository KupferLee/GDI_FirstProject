#include <cstdlib>

#include "raylib.h"

#include "config.h"


//initialization within main()
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
    Texture2D rickTexture = LoadTexture("assets/graphics/pixelRick.png");
    Texture2D steveTexture = LoadTexture("assets/graphics/Steve_Gamma.png");

   
    movementSpeed = 5;
    framesCounter = 0;

    position.x = 350;
    position.y = 100;
    
    

    GameScreen currentScreen = LOGO;
    

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        
       
        //tracking if steve touches the edges of the screen
       /*
       if (position.x <= 960 || position.x >= 0)
        {
            position.x * -1;
        }
        */

        //ping pong
        /*
        //change direction if hit a wall
        if (position.x >= Game::ScreenWidth - steveTexture.width || position.x <= 0)
        {
            movementSpeed = movementSpeed * -1;
        }

        //position changes with movement speed
        position.x += movementSpeed;
        */

        //bildschirmbegrenzung
        if (position.x >= Game::ScreenWidth - steveTexture.width || position.x <= 0)
        {
        
        }

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
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GAMEPLAY;
                }

            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = ENDING;
                }

                //press W A S D to move
                //if d and right border isnt touched
                if (IsKeyDown(KEY_D) && position.x <= Game::ScreenWidth - steveTexture.width)
                {
                    position.x += movementSpeed; //cirlce slowly goes right
                }
                //if a and left border ist touched
                else if (IsKeyDown(KEY_A) && position.x >= 0)
                {
                    position.x -= movementSpeed; //circle goes left
                }
                //if w and upper border isnt touched
                else if (IsKeyDown(KEY_W) && position.y >= 0)
                {
                    position.y -= movementSpeed; //circle goes up
                }
                //if s and lower border isnt touched
                else if (IsKeyDown(KEY_S) && position.y <= Game::ScreenHeight - steveTexture.height)
                {
                    position.y += movementSpeed; //circle goes down
                }
                

            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER))
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

        ClearBackground(WHITE);
            
            switch (currentScreen)
            {
                
                case LOGO:
                {
                    //Draw LOGO screen here!
                    DrawRectangle(0, 0, Game::ScreenWidth, Game::ScreenHeight, LIGHTGRAY);
                    DrawText("LOGO SCREEN", 20, 20, 40, GRAY);
                    DrawText("WAIT for 2 SECONDS...", 370, Game::ScreenHeight /2, 20, GRAY);

                } break;       
                case TITLE:
                {
                    //Draw TITLE screen here!
                    DrawRectangle(0, 0, Game::ScreenWidth, Game::ScreenHeight, GREEN);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 240, Game::ScreenHeight /2, 20, DARKGREEN);

                } break;
                case GAMEPLAY:
                {
                    //Draw Game Screen here
                    //order equals order of layers
                    DrawRectangle(0, 0, Game::ScreenWidth, Game::ScreenHeight, SKYBLUE);
                    //DrawTexture(rickTexture, 10, 100, WHITE);
                    DrawTextureV(steveTexture, position, WHITE);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 240, 500, 20, DARKBLUE);

                    //TO DO: flip Steve vertically when moved with A/D

                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, Game::ScreenWidth, Game::ScreenHeight, YELLOW);
                    DrawText("ENDING SCREEN", 20, 20, 40, ORANGE);
                    DrawText("PRESS ENTER to RETURN to TITLE SCREEN", 240, Game::ScreenHeight/2, 20, ORANGE);
                } break;
                default: break;
            }

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(rickTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
