#pragma once
#include "Unit.h"
#include "Bullet.h"
class Player :
	public Unit
{
public:
	Player();
	~Player();

	void render();
	void update(float dt);

};

