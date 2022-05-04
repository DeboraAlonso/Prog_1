#pragma once

#include <SFML/Graphics.hpp>

#define HEIGHT 800
#define WIDTH 600
#define BPP 60

using namespace sf;

class Game
{
public:

	Game();

	//void update();

	void loop();

private:

	RenderWindow Wind;

	Texture backg_tx;

	Sprite backg_sp;

	Event evt;


};

