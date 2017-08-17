#pragma once
#include "GameObject.h"
class Unit
	: public GameObject
{
public:
	Unit(const string& image_path,
		float collision_radius,
		float speed,
		float fire_delay_origin,
		int hp,
		Team team);
	virtual ~Unit();

	virtual void update(float dt) = 0;
	bool collides(const Unit& other) const;
	bool is_dead() const;

	float collision_radius;

	float speed;
	float fire_delay_origin;
	float fire_delay;
	int hp;
	int hp_origin;
	Team team;
};

