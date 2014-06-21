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
		if ((_direction = (rand() % 100) / 50))
			_sprite.setScale(-1, 1);
		_sprite.setPosition(-1100 + (rand() % 2200), 500);
	}
	~Pigeon() {}

	void	update(sf::RenderWindow &window, std::vector<sf::Sprite*> &poop)
	{
		if (_direction)
		{
			_sprite.setPosition((int)_sprite.getPosition().x + 1, 500);
			if (_sprite.getPosition().x > 1200)
				init();
		}
		else
		{
			_sprite.setPosition((int)_sprite.getPosition().x - 1, 500);
			if (_sprite.getPosition().x < -(long int)_texture.getSize().x)
				init();
		}
		for (auto it = poop.begin(); it != poop.end(); ++it)
		{
			if ((*it)->getPosition().x >= _sprite.getPosition().x &&
				(*it)->getPosition().x <= _sprite.getPosition().x + 10)
				_sprite.setScale(1.2, 1.2);
		}
		window.draw(_sprite);
	}

private:
	void	init(void)
	{
		if (_direction)
			_sprite.scale(-1, 1);
		if ((_direction = (rand() % 100) / 50))
		{
			_sprite.setPosition(-(int)_texture.getSize().x - (rand() % 1100), 500);
			_sprite.setScale(-1, 1);
		}
		else
			_sprite.setPosition(1200 + (rand() % 1100), 500);
	}

private:
	bool		_direction;

	sf::Texture	_texture;
	sf::Sprite	_sprite;
};

