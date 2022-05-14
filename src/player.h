#pragma once

#include "actor.h"

class player
{
public:
	player();
	~player();
	
	Texture2D texture;
	Vector2 position;

	int movement_speed;

	void update();
	void draw();
	
};