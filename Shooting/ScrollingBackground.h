#pragma once
#include "GameObject.h"

class ScrollingBackground :
	public GameObject
{
public:
	ScrollingBackground();
	~ScrollingBackground();

	void render();
	void update(float dt);

	float first_y;
	float second_y;

	float speed;
};

