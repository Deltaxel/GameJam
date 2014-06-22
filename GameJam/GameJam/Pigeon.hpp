#pragma once

#include <stdlib.h>

#include "SFML/Graphics.hpp"
#include "Caca.hpp"

class Pigeon
{
public:
	Pigeon()
	{
		_texture.loadFromFile("ressources\pigeon.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1,1);
		if ((_direction = ((rand() % 100) / 50) ? true : false))
			_sprite.setScale(-1, 1);
		_sprite.setPosition(-1100 + (float)(rand() % 2200), 500);
	}
	~Pigeon() {}

	void	update(sf::RenderWindow &window, std::list<Caca *> &poop, int ret, int &score)
	{
		if (_direction)
		{
			_sprite.setPosition(_sprite.getPosition().x + 1.0f, 500);
			if (_sprite.getPosition().x > 1200)
				init();
		}
		else
		{
			_sprite.setPosition(_sprite.getPosition().x - 1.0f, 500);
			if (_sprite.getPosition().x < -(long int)_texture.getSize().x)
				init();
		}
		for (auto it = poop.begin(); it != poop.end(); ++it)
		{
			if ((*it)->getPosition().y>= _sprite.getPosition().y
				&& (*it)->getPosition().x + (*it)->getSize().x >= _sprite.getPosition().x - (_direction ? _texture.getSize().x : 0)
				&& (*it)->getPosition().x <= _sprite.getPosition().x + _texture.getSize().x - (_direction ? _texture.getSize().x : 0))
			{
				_sprite.setScale(1.2f, 1.2f);
				if (ret == 3)
					score += 50;
				else if (ret == 2)
					score += 30;
			}
			else
			{
				if (ret == 1)
				{
					score -= 10;
					if (score < 0)
						score = 0;			
				}
			}
		}
		window.draw(_sprite);
	}

private:
	void	init(void)
	{
		if (_direction)
			_sprite.scale(-1, 1);
		if ((_direction = ((rand() % 100) / 50) ? true : false))
		{
			_sprite.setPosition(-(float)_texture.getSize().x - (float)(rand() % 1100), 500.0f);
			_sprite.setScale(-1.0f, 1.0f);
		}
		else
			_sprite.setPosition(1200.0f + (float)(rand() % 1100), 500.0f);
	}

private:
	bool		_direction;

	sf::Texture	_texture;
	sf::Sprite	_sprite;
};

