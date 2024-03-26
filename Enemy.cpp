#include "Enemy.h"
#include <iostream>


void Enemy::Initialize()
{
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

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(2, 2));
	}
	else
	{
		std::cout << "Enemy image failed to Loaded!" << std::endl;
	}
}

void Enemy::Update()
{
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
