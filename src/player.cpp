#include "player.h"

player::player()
{
	this->texture = LoadTexture("assets/graphics/player.png");
	//this->position.x = Game::ScreenWidth / 2 - this->texture.width / 2;
    this->position.x = 20;
    this->position.y = 20;
    this->movement_speed = 5;
}

player::~player()
{
	UnloadTexture(this->texture);
}

void player::update()
{
    //press W A S D to move
                //if d and right border isnt touched
    if (IsKeyDown(KEY_D) && this->position.x <= Game::ScreenWidth - this->texture.width)
    {
        this->position.x += this->movement_speed; //cirlce slowly goes right
    }
    //if a and left border ist touched
    else if (IsKeyDown(KEY_A) && this->position.x >= 0)
    {
        this->position.x -= this->movement_speed; //circle goes left
    }
    //if w and upper border isnt touched
    else if (IsKeyDown(KEY_W) && this->position.y >= 0)
    {
        this->position.y -= this->movement_speed; //circle goes up
    }
    //if s and lower border isnt touched
    else if (IsKeyDown(KEY_S) && this->position.y <= Game::ScreenHeight - this->texture.height)
    {
        this->position.y += this->movement_speed; //circle goes down
    }
}

void player::draw()
{
    DrawTexture(this->texture, this->position.x, this->position.y, WHITE);
}