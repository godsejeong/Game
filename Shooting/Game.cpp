#include "pch.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::init(sf::RenderWindow* window) {
	Game::instance().window = window;
	Game::instance().scene = new GameScene();
}

Game& Game::instance()
{
	static Game game;
	return game;
}