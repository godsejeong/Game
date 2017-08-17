#pragma once
#include "GameScene.h"
class Game
{
public:
	Game();
	~Game();

	GameScene* scene;
	sf::RenderWindow* window;

	static void init(sf::RenderWindow* window);
	static Game& instance();
};

