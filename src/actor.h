#pragma once

#include <cstdlib>
#include "raylib.h"
#include "config.h"

class actor
{
public:
	Texture2D texture;
	Vector2 position;
	Image image;

	int movement_speed = 3;
	int scale_factor = 4;

	//later
	//hp
	//attack points
};