#include <cstdlib>
#include "raylib.h"
#include "config.h"

#include "sprite.h"
#include "player.h"


//method to init a circle that bounces off the edges
void InitCircle(Texture2D texture, int pos_x, int pos_y, int speed)
{
    //TO DO: changing position
}

//method to draw a circle between begin drawing and end drawing
void DrawCircle(Texture2D texture, int pos_x, int pos_y, Color color)
{
    DrawTexture(texture, pos_x, pos_y, color);
}


//initialization within main()
int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

    

    typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } Gamescreen;
    

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    player* this_player = new player;

    /*
    Texture2D rickTexture = LoadTexture("assets/graphics/pixelRick.png");
    Texture2D player_texture = LoadTexture("assets/graphics/player.png");
    Texture2D circleTexture = LoadTexture("assets/graphics/circle.png");
    Texture2D foxTexture16 = LoadTexture("assets/graphics/Fox_Spirit16.png");
    Texture2D foxTexture32 = LoadTexture("assets/graphics/Fox_Spirit32.png");

    Vector2 playerPos;
    Vector2 circlePosV;
    int movementSpeed;
    int playerSpeed;
    
    int screenW;
    int screenH;
    int circlePos_x;
    int circlePos_y;
    */

    //movementSpeed = 5;
    //playerSpeed = 5;
    int framesCounter = 0;

    /*
    playerPos.x = 350;
    playerPos.y = 100;
    circlePosV.x = 10;
    circlePosV.y = 10;
    circlePos_x = 200;
    circlePos_y = 20;
    */

    //Sprite spRick(450, 200, LoadTexture("assets/graphics/pixelRick.png"));
    
    //Sprite spRick;
    //spRick.pos_y = 40;
    //spRick.pos_y = 20;
    //spRick.texture = LoadTexture("assets/graphics/pixelRick.png");
    
    
    //sets default to screen whith which the game shall start when being executed
    GameScreen currentScreen = LOGO;

    //Frames Per Second are kept to 60 frames per second
    SetTargetFPS(60);
    
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        

        //TITLE screen
        //ping pong
        //change direction if hit a wall
        /*
        if (circlePosV.x >= Game::ScreenWidth - circleTexture.width || circlePosV.x <= 0)
        {
            movementSpeed = movementSpeed * -1;
        }
        else if (circlePosV.y >= Game::ScreenHeight - circleTexture.height || circlePosV.y <= 0)
        {
            movementSpeed = movementSpeed * -1;
        }
        */

        
        
        //position changes with movement speed
        //circlePosV.x += movementSpeed;
        //circlePosV.y += movementSpeed;


        //Gameplay Screen
        switch (currentScreen) {
            
            case LOGO:
            {
                //update frames variables here

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

                this_player->update();
                /*
                //press W A S D to move
                //if d and right border isnt touched
                if (IsKeyDown(KEY_D) && playerPos.x <= Game::ScreenWidth - player_texture.width)
                {
                    playerPos.x += playerSpeed; //cirlce slowly goes right
                }
                //if a and left border ist touched
                else if (IsKeyDown(KEY_A) && playerPos.x >= 0)
                {
                    playerPos.x -= playerSpeed; //circle goes left
                }
                //if w and upper border isnt touched
                else if (IsKeyDown(KEY_W) && playerPos.y >= 0)
                {
                    playerPos.y -= playerSpeed; //circle goes up
                }
                //if s and lower border isnt touched
                else if (IsKeyDown(KEY_S) && playerPos.y <= Game::ScreenHeight - player_texture.height)
                {
                    playerPos.y += playerSpeed; //circle goes down
                }
                */
                

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
                    DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 240, 500, 20, DARKGREEN);
                    //DrawTextureV(circleTexture, circlePosV, BLUE);
                    //spRick.Draw();

                } break;
                case GAMEPLAY:
                {
                    //Draw Game Screen here
                    //order equals order of layers
                    DrawRectangle(0, 0, Game::ScreenWidth, Game::ScreenHeight, YELLOW);
                    //DrawTexture(rickTexture, 10, 100, WHITE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, ORANGE);
                    //DrawTexture(foxTexture16, 400, 200, WHITE);
                    //DrawTexture(foxTexture32, 40, 60, WHITE);
                    DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 240, 500, 20, ORANGE);
                    //DrawTextureV(player_texture, playerPos, WHITE);
                    this_player->draw();
                    
                    //TO DO: if wasd is pressed delete text
                    
                    //TO DO: flip Steve vertically when moved with A/D

                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, Game::ScreenWidth, Game::ScreenHeight, RED);
                    DrawText("ENDING SCREEN", 20, 20, 40, BLACK);
                    DrawText("PRESS ENTER to RETURN to TITLE SCREEN", 240, 500, 20, BLACK);
                } break;
                default: break;
            }

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    //UnloadTexture(player_texture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
