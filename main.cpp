
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{

	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	
	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / m;

	normalizedVector.y = vector.y / m;

	return normalizedVector;
	
}

int main()
{

	
	//-----------------------INITIALIZE----------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "RPG Game",sf::Style::Default,settings);	
	
	std::vector<sf::RectangleShape> bullets;

	
	float bulletSpeed = 1.0f;
	

	//-----------------LOAD ENEMY----------------------------
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

	if (enemyTexture.loadFromFile("Assets/enemy/enemy.png"))
	{
		std::cout << "Enemy image Loaded!" << std::endl;
		enemySprite.setTexture(enemyTexture);
		enemySprite.setPosition(sf::Vector2f(700, 400));

		int XIndex = 0;
		int YIndex = 2;

		enemySprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		enemySprite.scale(sf::Vector2f(2, 2));
	}
	else
	{
		std::cout << "Enemy image failed to Loaded!" << std::endl;
	}
	

	//-----------------LOAD PLAYER----------------------------
	
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/player/textures/spritesheet.png"))
	{
		std::cout << "Player image Loaded!" << std::endl;
		playerSprite.setTexture(playerTexture);

		int XIndex = 0;
		int YIndex = 0;

		playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex *  64, 64, 64));
		playerSprite.scale(sf::Vector2f(2, 2));
		playerSprite.setPosition(sf::Vector2f(100, 100));
	}
	else
	{
		std::cout << "Player image failed to Loaded!" << std::endl;
		bullets[bullets.size() - 1].setPosition(playerSprite.getPosition());


		//sf::RectangleShape bullet(sf::Vector2f(25,10));
	}
	
	
	//-------Calculate direction of the bullet -----------

	//sf::Vector2f bulletDirection = enemySprite.getPosition() - bullet.getPosition();

	//bulletDirection = NormalizeVector(bulletDirection);

	// main game loop
	while (window.isOpen())
	{

		//--------------------UPDATE--------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		
		
		


		sf::Vector2f position = playerSprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			playerSprite.setPosition(position +sf::Vector2f(0, -1));

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(20, 10)));
			
			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());
			
			
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();

			bulletDirection = NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
		
		//--------------------UPDATE--------------------

		//---------------------DRAW---------------------

		
		window.clear(sf::Color::Green);
		
		window.draw(playerSprite);
		window.draw(enemySprite);
		
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}

		window.display();
	}

	return 0;
}

