
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{

	//-----------------------INITIALIZE----------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game",sf::Style::Default,settings);	
	//-----------------------INITIALIZE----------------
	//-----------------LOAD----------------------------
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
	}
	else
	{
		std::cout << "Player image failed to Loaded!" << std::endl;
	}

	
	//-----------------LOAD----------------------------

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

		
		//--------------------UPDATE--------------------

		//---------------------DRAW---------------------

		//---------------------DRAW---------------------
		window.clear(sf::Color::Green);
		
		window.draw(playerSprite);

		window.display();
	}

	return 0;
}

