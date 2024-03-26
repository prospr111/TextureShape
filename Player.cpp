#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize()
{
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/player/textures/spritesheet.png"))
	{
		std::cout << "Player image Loaded!" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(2, 2));
		sprite.setPosition(sf::Vector2f(100, 100));
	}
	else
	{
		std::cout << "Player image failed to Loaded!" << std::endl;
		


		//sf::RectangleShape bullet(sf::Vector2f(25,10));
	}

}

void Player::Update(Enemy& enemy)
{
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.setPosition(position + sf::Vector2f(1, 0));


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.setPosition(position + sf::Vector2f(-1, 0));


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		sprite.setPosition(position + sf::Vector2f(0, -1));


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.setPosition(position + sf::Vector2f(0, 1));


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		bullets.push_back(sf::RectangleShape(sf::Vector2f(20, 10)));

		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());


	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();

		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}

	
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}

}
