#include "pch.h"
#include "Unit.h"
#include "Game.h"



Unit::Unit(
	const string& image_path,
	float collision_radius,
	float speed,
	float fire_delay_origin,
	int hp,
	Team team
)
	:GameObject(image_path),
	speed(speed),
	collision_radius(collision_radius),
	fire_delay_origin(fire_delay_origin),
	fire_delay(0),
	hp(hp),
	hp_origin(hp),
	team(team)
{

	sprite.setOrigin(
		texture.getSize().x / 2,
 texture.getSize().y / 2);
}


Unit::~Unit()
{
}

bool Unit::collides(const Unit& other) const
{
	return
		get_distance(sprite.getPosition(), other.sprite.getPosition())
		< other.collision_radius + this->collision_radius;
}

bool Unit::is_dead() const
{
	return hp <= 0;
}
