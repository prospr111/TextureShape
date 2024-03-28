#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::White);
	boundingRectangle.setOutlineThickness(1);
	
	size = sf::Vector2i(64, 64);
		
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/player/textures/player.png"))
	{
		std::cout << "Player image Loaded!" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(100, 100));

		sprite.scale(sf::Vector2f(1, 1));
		boundingRectangle.setSize(sf::Vector2f(size.x + sprite.getScale().x, size.y * sprite.getScale().y));

		
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
	boundingRectangle.setPosition(sprite.getPosition());

	if (Math::DidRectCollide(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds()))
	{
		std::cout << "COLLISION " << std::endl;
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}

}
