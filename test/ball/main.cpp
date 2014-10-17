#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game.h"

int main(int argc, char ** argv)
{
	if (1 != argc && 3 != argc)
	{
		return(-1);
	}

    sf::Vector2u size(800, 600);

	if (3 == argc)
	{
		size.x = atoi(argv[1]);
		size.y = atoi(argv[2]);
	}

	sf::VideoMode vm(size.x, size.y);
	sf::ContextSettings settings;

	sf::RenderWindow window(vm, "ball", sf::Style::Default, settings);

	Game game(window);

	game.init();

	game.run();

	return 0;
}
