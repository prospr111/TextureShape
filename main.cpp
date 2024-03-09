
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{

	//-----------------------INITIALIZE----------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game",sf::Style::Default,settings);
	sf::CircleShape shape(50.0f,3);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(100.f, 100.f));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Magenta);

	sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
	
	rectangle.setSize(sf::Vector2f(100.f, 50.f));
	
	rectangle.setPosition(150.f, 150.f);
	rectangle.setOrigin(sf::Vector2f(rectangle.getSize() / 2.0f));
	rectangle.setRotation(45);
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setFillColor(sf::Color::Yellow);
	
	sf::CircleShape shape2(80.0f, 8);
	shape2.setFillColor(sf::Color::Red);
	shape2.setPosition(200.0f, 200.0f);
	shape2.setOutlineThickness(5);
	shape2.setOutlineColor(sf::Color::Black);
	
	sf::ConvexShape convex;
	convex.setPosition(250.0f, 250.0f);
	convex.setFillColor(sf::Color::Blue);
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(30.0f, 30.0f));
	convex.setPoint(1, sf::Vector2f(100.0f, 100.0f));
	convex.setPoint(2, sf::Vector2f(100.0f, 150.0f));
	convex.setPoint(0, sf::Vector2f(30.0f, 150.0f));
	
	sf::RectangleShape line(sf::Vector2f(150.0f, 5.0f));
	line.setPosition(150.0f, 150.0f);
	line.rotate(45.0f);

	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(20.f,20.f)),
		sf::Vertex(sf::Vector2f(150.f,150.f))

	};

	//-----------------------INITIALIZE----------------

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
		//--------------------UPDATE--------------------

		//---------------------DRAW---------------------

		//---------------------DRAW---------------------
		window.clear(sf::Color::Green);
		window.draw(shape);
		window.draw(rectangle);
		window.draw(shape2);
		window.draw(convex);
		window.draw(line);
		window.draw(line2, 2, sf::Lines);
		window.display();
	}

	return 0;
}

