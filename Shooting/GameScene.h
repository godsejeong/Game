#pragma once
#include "Player.h"
#include "ScrollingBackground.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	void spawn_enemy(float x);
	void spawn_bullet(Unit& owner, Bullet* bullet, sf::Vector2f pos_offset);

	void update(float dt);
	void render();

	
	Player* player;
	ScrollingBackground* background;

	sf::FloatRect screen_bounds;
	
	vector<Bullet*> bullets;
	vector<Unit*> enemies;
	vector<Unit*> units;

	float spawn_time;
	float spawn_time_origin;
};

