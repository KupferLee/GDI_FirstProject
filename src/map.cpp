#include "map.h"

map::map()
{
	this->texture = LoadTexture("assets/graphics/test_map.png");
	this->position.x = 0;
	this->position.y = 0;
}

map::~map()
{
	UnloadTexture(this->texture);
}