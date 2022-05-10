#include "Mario.h"

Mario::Mario()
{
	spr_grap();

}

void Mario::spr_grap()
{
	_Mario = Afichmation("assets/spritesheet.png", true, 104, 125);

	_Mario.Add("idle", { 0, 2, 1, 0, 2, 1, 2 }, 2.75f, true);

	//Otras animaciones complementarias y necesarias.
	_Mario.Add("run", { 3, 4, 5, 6, 7, 8, }, 7, true);

	_Mario.Add("jump", { 12, 13, 14, 15 }, 9, true);

	//Ejecuto una animación a apartir de su String. En este caso la denominada Idle.
	_Mario.Play("idle");

	//Puedo utilizar métodos propios de Sprite, en este caso setScale.
	_Mario.setScale(Vector2f(0.90f, 0.85f));

	_Mario.setPosition(_Mario.getPosition().x, 478);

	//_Mario.setRotation(-180);/*te roté el personaje poruque por alguna razón Mario quedaba patas para arriba*/
}

Afichmation Mario::getCharacter()
{
	return _Mario;
}


void Mario::update()
{
	//Afichmation update

	_Mario.Update();/*Hay que actualizar el propio Afichmation para que funcione la animación*/

}

void Mario::jumpControl()
{
	if (jump)
	{
		_Mario.setPosition(_Mario.getPosition().x, _Mario.getPosition().y - gravity);
	}
	else
	{
		_Mario.setPosition(_Mario.getPosition().x, _Mario.getPosition().y + gravity);
	}

	if (_Mario.getPosition().y >= 478)
	{
		_Mario.setPosition(_Mario.getPosition().x, 478);

		ground;
	}

	if (_Mario.getPosition().y <= 478 - 150)
	{
		jump;
	}

}

void Mario::controller(Event e)
{
	if (e.type == Event::KeyPressed)
	{
		if (e.key.code == Keyboard::Left)
		{
			_Mario.Play("run");

			_Mario.FlipX(false);

			_Mario.move(-2, 0);
		}

		if (e.key.code == Keyboard::Right)
		{
			_Mario.Play("run");

			_Mario.FlipX(true);

			_Mario.setPosition(_Mario.getPosition().x + 2, _Mario.getPosition().y);
		}

		if (e.key.code == Keyboard::Up)
		{
			if (ground && !jump)
			{
				_Mario.Play("jump");

				_Mario.FlipY(false);

				jump;

				!ground;

			}
		}
	}
}