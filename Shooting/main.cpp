#include "pch.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE h_inst,
	HINSTANCE h_prev_inst,
	LPSTR cmd_line,
	int cmd_show)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), L"Ã¢Á¦¸ñ", sf::Style::Close,settings);

	Game::init(&window);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		sf::Time elapsed = clock.restart();
		Game::instance().scene->update(elapsed.asSeconds());
		Game::instance().scene->render();

		window.display();
	}
}