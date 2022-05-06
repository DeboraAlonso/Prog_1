#include "Mario.h"

Mario::Mario()
{
	spr_grap();


}

void Mario::spr_grap()
{
	_Mario = Afichmation("assets/spritesheet.png", true, 100, 110);

	_Mario.Add("idle", { 0, 2, 1, 0, 2 }, 8, false);

	//Otras animaciones complementarias y necesarias.
	_Mario.Add("run", { 3, 4, 5, 4 }, 8, true);

	//Ejecuto una animación a apartir de su String. En este caso la denominada Idle.
	_Mario.Play("idle");

	//Puedo utilizar métodos propios de Sprite, en este caso setScale.
	_Mario.setScale(Vector2f(30.f, 30.f));
}

Afichmation Mario::getCharacter()
{
	return _Mario;
}


void Mario::update()
{

	while (Wind.pollEvent(m_evt))
	{
		switch (m_evt.key.code)
		{
		case Keyboard::Left:

			_Mario.Play("run");

			_Mario.FlipX(false);

			_Mario.move(-2, 0);

			break;

		case Keyboard::Right:

			_Mario.Play("run");

			_Mario.FlipX(true);

			_Mario.setPosition(_Mario.getPosition().x + 2, _Mario.getPosition().y);

			break;
		}
	}
}