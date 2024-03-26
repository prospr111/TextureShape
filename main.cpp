
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

int main()
{
	

	//-----------------------INITIALIZE----------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "RPG Game",sf::Style::Default,settings);	
	
	
	
	Player player;
	player.Initialize();
	player.Load();

	Enemy enemy;
	enemy.Initialize();
	enemy.Load();	
	
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

		enemy.Update();
		player.Update(enemy);
		//---------------------DRAW---------------------
				
		window.clear(sf::Color::Green);

		player.Draw(window);
		enemy.Draw(window);	
		
		
		
		window.display();
	}

	return 0;
}

