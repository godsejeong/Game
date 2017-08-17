#include "pch.h"
#include "ScrollingBackground.h"
#include "Game.h"


ScrollingBackground::ScrollingBackground()
	:GameObject("background.jpg"), speed(400)
{
	float texture_height = texture.getSize().y;
	first_y = texture_height / 2;
	second_y = -texture_height / 2;
}


ScrollingBackground::~ScrollingBackground()
{
}


void ScrollingBackground::render()
{
	sprite.setPosition(0, first_y);
	Game::instance().window->draw(sprite);

	sprite.setPosition(0, second_y);
	Game::instance().window->draw(sprite);
}


void ScrollingBackground::update(float dt)
{
	first_y += speed * dt;
	second_y += speed * dt;

	if (first_y >= GAME_HEIGHT)
		first_y -= texture.getSize().y * 2;
	if (second_y >= GAME_HEIGHT)
		second_y -= texture.getSize().y * 2;
}