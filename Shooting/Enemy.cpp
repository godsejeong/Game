#include "pch.h"
#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
	:Unit("h.png", 50, 100, 0.3, 3, Team::ENEMY) 
{
}


Enemy::~Enemy()
{
}

void Enemy::update(float dt) {

	fire_delay += dt;

	if (sprite.getPosition().y < 100) {
		sprite.move(0, 100 * dt);
	}
	else if (fire_delay > fire_delay_origin) {
		Game::instance().scene->spawn_bullet(
			*this,
			new Bullet(1000, sf::Vector2f(0, 1)),
			sf::Vector2f(0, (float)texture.getSize().y / 2)
		);

	Game::instance().scene->spawn_bullet(
		*this,
		new Bullet(1000, sf::Vector2f(1, 1)),
		sf::Vector2f(0, (float)texture.getSize().y / 2)
	);

	Game::instance().scene->spawn_bullet(
		*this,
		new Bullet(1000, sf::Vector2f(-1, 1)),
		sf::Vector2f(0, (float)texture.getSize().y / 2)
	);

	fire_delay = 0;
	}
}

