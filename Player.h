#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

class Player
{
public:
	void Initialize();
	void Load();
	void Update(Enemy& enemy);
	void Draw(sf::RenderWindow& window);

public:
	

	sf::Vector2i size;
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;
	
	sf::Sprite sprite;
	sf::RectangleShape boundingRectangle;
	
	
};

