#include "pch.h"
#include "Bullet.h"


Bullet::Bullet(float speed, sf::Vector2f direction)
	:Unit("bullet.png",5,speed, 0,0, Team::PLAYER), direction(direction)
{
	sprite.setOrigin(
		texture.getSize().x / 2,
		texture.getSize().y
	);


	//방향 정규화
	float length =
	sqrt(
		pow(direction.x, 2) + pow(direction.y, 2)
	);

	direction /= length;
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt) {
	sf::Vector2f velocity = direction * speed * dt;
	sprite.move(velocity);
}