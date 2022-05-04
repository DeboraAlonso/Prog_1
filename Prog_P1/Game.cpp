#include "Game.h"

Game::Game()
{
	Wind.create(VideoMode(HEIGHT, WIDTH, BPP), "Prog practice part 1");

	Wind.setVerticalSyncEnabled(BPP);

	backg_tx.loadFromFile("Assets/backgroung.png");
	backg_tx.setTexture(backg_tx);

	backg_sp.loadFromFile("Assets/spritesheet.png");
	backg_sp.setTexture(backg_sp);

	backg_sp.setScale(30, 30);
}

void Game::loop()
{
	while (Wind.isOpen())
	{
		while (Wind.pollEvent(evt))
		{
			switch (evt.key.code)
			{

			case Keyboard::Escape:

				exit(1);

				break;

			case Keyboard::Up:

				break;

				case Keyboard::

			}
		}
	}
}