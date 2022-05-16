#pragma once

#include "actor.h"

class player : public actor
{
public:
	player();
	~player();
	
	

	//int movement_speed;

	void update();
	void draw();
	
};