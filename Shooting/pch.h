#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

#define NOMINMAX

#include <Windows.h>
#include <SFML\Graphics.hpp>


#define GAME_WIDTH 740
#define GAME_HEIGHT 740

using namespace std;

//¿­°ÅÇü 
enum class Team
{
	PLAYER,
	ENEMY
};

float random(float from, float to);
inline float get_distance(const sf::Vector2f& a, const sf::Vector2f& b)
{
	return sqrt(pow(b.y - a.y, 2) + pow(b.x - a.x, 2));
}