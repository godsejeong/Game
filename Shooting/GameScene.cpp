#include "pch.h"
#include "GameScene.h"
#include "Enemy.h"

GameScene::GameScene()
	:screen_bounds(0, 0, GAME_WIDTH, GAME_HEIGHT),
	spawn_time(2),
	spawn_time_origin(6)
{
	player = new Player();
	player->sprite.setPosition(GAME_WIDTH / 2, GAME_HEIGHT - 200);
	units.push_back(player);

	background = new ScrollingBackground();
}


GameScene::~GameScene()
{
}

void GameScene::render()
{
	background->render();
	for (Bullet* b : bullets)
		b->render();
	for (Unit* u : units)
		u->render();
}

void GameScene::update(float dt)
{
	spawn_time -= dt;

	if (spawn_time < 0)
	{
		spawn_time = spawn_time_origin;
		spawn_time_origin -= 0.05;

		spawn_enemy(random(30, GAME_WIDTH - 30));
	}

	background->update(dt);
	for (Bullet* b : bullets)
	{
		b->update(dt);

		if (!screen_bounds.intersects(b->sprite.getGlobalBounds()))
		{
			b->deleting = true;
		}
	}

	for (Unit* u : units)
	{
		u->update(dt);

		if (u->deleting)
			continue;

		for (Bullet* b : bullets)
		{
			if (b->deleting)
				continue;

			if (b->team != u->team && u->collides(*b))
			{
				b->deleting = true;
				u->hp--;

				if (u == player)
				{
					exit(0);
				}

				if (u->is_dead())
					u->deleting = true;
			}
		}
	}

	// erase-remove idiom
	bullets.erase(remove_if(bullets.begin(), bullets.end(),
		[&](Bullet* b) {
		bool is_deleting = b->deleting;
		if (is_deleting)
			delete b;
		return is_deleting;
	}), bullets.end());

	units.erase(remove_if(units.begin(), units.end(),
		[&](Unit* b) {
		bool is_deleting = b->deleting;
		if (is_deleting)
			delete b;
		return is_deleting;
	}), units.end());
}

void GameScene::spawn_bullet(Unit& owner, Bullet* bullet, sf::Vector2f pos_offset)
{
	bullet->team = owner.team;

	bullet->sprite.setPosition(
		owner.sprite.getPosition()
		+ pos_offset
	);

	bullets.push_back(bullet);
}

void GameScene::spawn_enemy(float x)
{
	Enemy* e = new Enemy();

	e->sprite.setPosition(x, -100);

	enemies.push_back(e);
	units.push_back(e);
}