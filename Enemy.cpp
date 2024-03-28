#include "Enemy.h"
#include <iostream>


void Enemy::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/enemy/enemy.png"))
	{
		std::cout << "Enemy image Loaded!" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(700, 400));

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.scale(sf::Vector2f(1, 1));

		
		boundingRectangle.setSize(sf::Vector2f(size.x + sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout << "Enemy image failed to Loaded!" << std::endl;
	}
}

void Enemy::Update()
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(boundingRectangle);
	window.draw(sprite);
}
