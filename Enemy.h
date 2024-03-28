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
	sf::RectangleShape boundingRectangle;

	sf::Vector2i size;
private:
	sf::Texture texture;
	
};

