#include "Game.h"

Game::Game()
{
	gamescreen();

	fps();

	backg_grap();

}

void Game::gamescreen()
{
	Wind.create(VideoMode(WIDTH, HEIGHT, 32), "Prog practice part 1");//bits per pixel refiere a la profundidad de color en bits a utilizar
	/*En videomode primero WIDTH y luego HEIGHT te intercambio los valores de las constantes*/
}

void Game::fps()
{
	Wind.setVerticalSyncEnabled(true);//la habilitación de sincronización vertical requiere un true o false
}

void Game::backg_grap()
{
	backg_tx.loadFromFile("Assets/Background.jpg");
	backg_sp.setTexture(backg_tx);
}

void Game::draw()
{
	Wind.draw(backg_sp);

	Wind.draw(Character.getCharacter());

	Wind.display();
}

void Game::loop()// te dejé algunas correcciones de orden y de control de eventos
{
	Event e;
	while (Wind.isOpen())
	{
		while (Wind.pollEvent(e))
		{
			switch (e.key.code)
			{

			case Event::Closed:

				Wind.close();

				break;

			case Keyboard::Escape:

				exit(1);

				break;

			}
		}
		Character.controller(e);

		Character.update();

		Wind.clear();

		draw();

	}
}