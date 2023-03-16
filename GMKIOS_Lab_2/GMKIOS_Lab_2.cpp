#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
const double PI = 3.141592653589793238463;


int main()
{
	sf::ContextSettings settings = sf::ContextSettings();
	settings.antialiasingLevel = 16;
	RenderWindow window(VideoMode(1920, 1080), "Lab 2", 7U, settings);
	window.setFramerateLimit(60);
	float circleradius = 100.0f;
	CircleShape diafragmborder(circleradius, 30);
	diafragmborder.setFillColor(Color::Transparent);
	diafragmborder.setOutlineColor(Color::White);
	diafragmborder.setOutlineThickness(10.0f);
	diafragmborder.setPosition(Vector2f(window.getSize().x / 2.0f - circleradius , window.getSize().y / 2.0f - circleradius ));
	CircleShape diafragmoutborder(circleradius, 40);
	diafragmoutborder.setFillColor(Color::Transparent);
	diafragmoutborder.setOutlineColor(Color::Black);
	diafragmoutborder.setOutlineThickness(400.0f);
	diafragmoutborder.setPosition(Vector2f(window.getSize().x / 2.0f - circleradius, window.getSize().y / 2.0f - circleradius));



	int pelustcount = 6;
	float angle = 0.0f;

	Vector2f circlecenter = Vector2f(window.getSize().x / 2, window.getSize().y / 2);
	 
	bool useauto = true;

	window.setKeyRepeatEnabled(true);
	Event event;
	sf::Clock clock;
	std::cout << sin(90.0f * PI / 180);
	while (window.isOpen())
	{
		sf::ConvexShape convex;
		convex.setPointCount(3);
		convex.setPoint(0, sf::Vector2f(0, 0));
		convex.setPoint(1, sf::Vector2f(120, -90));
		convex.setPoint(2, sf::Vector2f(120, 120));
		//convex.setPosition(circlecenter);
		convex.setFillColor(Color::White);
		convex.setOutlineColor(Color::Red);
		convex.setOutlineThickness(2);
		
		

		while (window.pollEvent(event))
		{
			if (event.mouseButton.button == sf::Mouse::Left) {
				angle -= 5.0f;
			}

			if (event.mouseButton.button == sf::Mouse::Right) {
				angle += 5.0f;
			}
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
				if (event.KeyReleased) {
					useauto = !useauto;
				}
			}

			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.clear();
		
		for (int i = pelustcount - 1; i >= 0; i--) {
			
			convex.setPosition(
				circlecenter.x +
				cos((360.0f / pelustcount * i * PI / 180)) * circleradius,
				circlecenter.y +
				sin((360.0f / pelustcount * i * PI / 180)) * circleradius
				
			);
			if (useauto) {
				convex.setRotation(cos(clock.getElapsedTime().asSeconds())*30 - 25.0f - 85.0f + 360.0f / pelustcount * i);
			}
			else {
				convex.setRotation(angle - 80.0f + 360.0f / pelustcount * i);
			}

			window.draw(convex);
		}
		
		window.draw(diafragmoutborder);
		window.draw(diafragmborder);
		window.display();
	}

	return 0;

}
