#pragma once

#include <SFML/Graphics.hpp>
#include "Afichmation.h"

using namespace sf;

class Mario : public Afichmation
{
public:

	Mario();

	void update();

	void spr_grap();

	Afichmation getCharacter();

private:

	Texture Mario_tx;

	Sprite Mario_sp;

	Afichmation _Mario;

	RenderWindow Wind;

	Event m_evt;
};

