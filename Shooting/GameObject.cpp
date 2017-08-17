#include "pch.h"
#include "GameObject.h"
#include "Game.h"


GameObject::GameObject(const string& image_path)
	:deleting(false)
{
	texture.loadFromFile(image_path);
	texture.setSmooth(true);
	sprite.setTexture(texture);
}


GameObject::~GameObject()
{
}

void GameObject::render() {
	Game::instance().window->draw(sprite);

}
