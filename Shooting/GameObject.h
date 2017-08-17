#pragma once

class GameObject
{
public:
	GameObject(const string& image_path);
	virtual ~GameObject();
	
	virtual void update(float dt) = 0;
	virtual void render();
	sf::Sprite sprite;
	sf::Texture texture;

	bool deleting;
};

