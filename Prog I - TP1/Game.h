#pragma once

#include <SFML/Graphics.hpp>
#include "Mario.h"

#define HEIGHT 600
#define WIDTH 800
#define BPP 60

using namespace sf;

class Game
{
public:

	Game();

	//void update();

	void gamescreen();

	void backg_grap();

	void fps();

	void draw();

	void loop();

private:

	RenderWindow Wind;

	Texture backg_tx;

	Sprite backg_sp;

	Event evt;

	Mario Character;


};

