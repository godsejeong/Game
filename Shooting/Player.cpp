#include "pch.h"
#include "Player.h"
#include "Game.h"

Player::Player()
	:Unit("top.png",20,400 ,0.1,5,Team::PLAYER)
{
}


Player::~Player()
{
}

void Player::render()
{
	Unit::render();


}

void Player::update(float dt)
{
	fire_delay += dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sprite.move(-speed * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sprite.move(speed * dt, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sprite.move(0, -speed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sprite.move(0, speed * dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (fire_delay < fire_delay_origin)
			return;

		Game::instance().scene->spawn_bullet(
			*this,
			new Bullet(1000, sf::Vector2f(0, -1)),
			sf::Vector2f(0, -(float)texture.getSize().y / 2)
		);

		fire_delay = 0;
	}
}



