#pragma once

#include "SFML/Graphics.hpp"

#include "Papi.hpp"

class Caca
{
public:
	Caca(Papi &papi)
	{
		_texture[0].loadFromFile("caca1.png");
		_texture[1].loadFromFile("caca2.png");
		_texture[2].loadFromFile("caca3.png");
		_texture[3].loadFromFile("caca4.png");
		_sprite.setTexture(_texture[0]);
		_sprite.setPosition(papi.getPosition().x + (papi.getSize().x / 2) - 50, papi.getPosition().y + 100);
		_sprite.setScale(0.2f, 0.2f);
	}
	~Caca(void) {}

	void	update(sf::RenderWindow &window)
	{
		if (_sprite.getPosition().y < 733)
		{
			_sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y + 15);
			_clock.restart();
		}
		else
		{
			_sprite.setPosition(_sprite.getPosition().x, 733);
			if (_frame < 3)
			{
				++_frame;
				_sprite.setTexture(_texture[_frame]);
			}
		}
		window.draw(_sprite);
	}
	
	bool	isAlive(void) const { return (_clock.getElapsedTime().asSeconds() < 1.0f); }

	sf::Vector2f	getPosition(void) const { return (_sprite.getPosition()); }
	sf::Vector2u	getSize(void) const { return (_texture[_frame].getSize()); }

private:
	int		_frame;

	sf::Texture	_texture[4];
	sf::Sprite	_sprite;

	sf::Clock	_clock;
};