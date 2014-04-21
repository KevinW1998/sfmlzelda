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
#if SFML_FULLSCREEN == 1
	sf::RenderWindow window(sf::VideoMode(SFML_WIDTH, SFML_HEIGHT), "SFML works!",sf::Style::Fullscreen);
#else
	sf::RenderWindow window(sf::VideoMode(SFML_WIDTH, SFML_HEIGHT), "SFML works!");
#endif
	
	bool pauseBeforeClose = false;

	window.setFramerateLimit(60);
	Game g(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
					window.close();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Pause)){
					window.close();
					pauseBeforeClose = true;
				}
			}
		}


		g.RunLoop();

	}

	if (pauseBeforeClose){
		system("pause");
	}

	return 0;
}