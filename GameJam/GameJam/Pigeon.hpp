#pragma once

#include <stdlib.h>

#include "SFML/Graphics.hpp"
#include "Caca.hpp"

class Pigeon
{
public:
	Pigeon()
	{
		_texture[0].loadFromFile("ressources/pigeon.png");
		_texture[1].loadFromFile("ressources/pigeon1.png");
		_sprite.setTexture(_texture[0]);
		_sprite.setScale(1, 1);
		if ((_direction = ((rand() % 100) / 50) ? true : false))
			_sprite.setScale(-1, 1);
		_sprite.setPosition(-1100 + (float)(rand() % 2200), 500);
		_shooted = false;
		_frame = 0;
	}
	~Pigeon() {}

	void	update(sf::RenderWindow &window, std::list<Caca *> &poop, int ret, int &score)
	{
		if (_shooted == false)
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
				if (_sprite.getPosition().x < -(long int)_texture[_frame].getSize().x)
					init();
			}
			auto it = poop.begin();
			bool ok;
			while (it != poop.end())
			{
				ok = false;
				if ((*it)->getPosition().y >= _sprite.getPosition().y
					&& (*it)->getPosition().x + (*it)->getSize().x >= _sprite.getPosition().x - (_direction ? _texture[_frame].getSize().x : 0)
					&& (*it)->getPosition().x <= _sprite.getPosition().x + _texture[_frame].getSize().x - (_direction ? _texture[_frame].getSize().x : 0))
				{
					if (ret == 3)
						score += 50;
					else if (ret == 2)
						score += 30;
					ok = true;
				}
				if (ok)
				{
					it = poop.erase(it);
					if (_shooted == false)
					{
						_shooted = true;
						_clock.restart();
					}
				}
				else
					++it;
			}
		}
		else
		{
			if (_frame < 1)
				++_frame;
			_sprite.setTexture(_texture[_frame]);
			if (_clock.getElapsedTime().asSeconds() > 1)
				init();
		}
		window.draw(_sprite);
	}

private:
	void	init(void)
	{
		_frame = 0;
		_sprite.setTexture(_texture[0]);
		if (_direction)
			_sprite.scale(-1, 1);
		if ((_direction = ((rand() % 100) / 50) ? true : false))
		{
			_sprite.setPosition(-(float)_texture[_frame].getSize().x - (float)(rand() % 1100), 500.0f);
			_sprite.setScale(-1.0f, 1.0f);
		}
		else
			_sprite.setPosition(1200.0f + (float)(rand() % 1100), 500.0f);
		_shooted = false;
	}

private:
	int			_frame;
	bool		_direction;
	bool		_shooted;

	sf::Texture	_texture[2];
	sf::Sprite	_sprite;

	sf::Clock	_clock;
};

