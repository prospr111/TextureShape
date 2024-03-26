#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{

public:
	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);

public:
	sf::Sprite sprite;

private:
	sf::Texture texture;
	
};

