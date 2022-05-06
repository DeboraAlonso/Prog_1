#include "Game.h"

Game::Game()
{
	
	gamescreen();

	fps();

	backg_grap();



	
}

void Game::gamescreen()
{
	Wind.create(VideoMode(HEIGHT, WIDTH, BPP), "Prog practice part 1");
}

void Game::fps()
{
	Wind.setVerticalSyncEnabled(BPP);
}

void Game::backg_grap()
{
	backg_tx.loadFromFile("Assets/Background.jpg");
	backg_sp.setTexture(backg_tx);
}

void Game::draw()
{
	Wind.draw(backg_sp);

	Character.getCharacter();

	Wind.display();
}

void Game::loop()
{
	while (Wind.isOpen())
	{
		
		Wind.clear();

		Character.update();

		draw();
	
	}
}