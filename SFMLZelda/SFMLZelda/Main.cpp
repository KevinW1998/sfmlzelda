#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include "stdafx.h"
#include "Game.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 480), "SFML works!");
	window.setFramerateLimit(60);
	Game g(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		g.RunLoop();

	}

	return 0;
}