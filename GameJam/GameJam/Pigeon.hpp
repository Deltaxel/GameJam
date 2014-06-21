#pragma once

#include <stdlib.h>
#include <SFML/Graphics.hpp>

class Pigeon
{
public:
	Pigeon()
	{
		_texture.loadFromFile("pigeon.png");
		_sprite.setTexture(_texture);
		if ((_direction = rand() % 2))
		{
			_sprite.setPosition(-(int)_texture.getSize().x - (rand() % 50), 500);
			_sprite.setScale(-1, 1);
		}
		else
			_sprite.setPosition(1200 + (rand() % 50), 500);
	}
	~Pigeon() {}

	void	update(void)
	{
		if (_direction)
		{
			_sprite.setPosition((int)_sprite.getPosition().x + 1, 500);
			if (_sprite.getPosition().x > 1200)
			{
				if ((_direction = rand() % 2))
				{
					_sprite.setPosition(-(int)_texture.getSize().x - (rand() % 50), 500);
					_sprite.setScale(-1, 1);
				}
				else
					_sprite.setPosition(1200 + (rand() % 50), 500);
			}
		}
		else
		{
			_sprite.setPosition((int)_sprite.getPosition().x - 1, 500);
			if (_sprite.getPosition().x < _texture.getSize().x)
			{
				if ((_direction = rand() % 2))
				{
					_sprite.setPosition(-(int)_texture.getSize().x - (rand() % 50), 500);
					_sprite.setScale(-1, 1);
				}
				else
					_sprite.setPosition(1200 + (rand() % 50), 500);
			}
		}

	}

private:
	bool		_direction;

	sf::Texture	_texture;
	sf::Sprite	_sprite;
};

