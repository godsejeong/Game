#pragma once
#include "Unit.h"
class Bullet :
	public Unit
{
public:
	Bullet(float speed, sf::Vector2f direction);
	~Bullet();

	void update(float dt);
	

	sf::Vector2f direction;
};

