#pragma once

#include "SFML/Graphics.hpp"

class Papi
{
public:
	enum Direction
	{
		None,
		Left,
		Right
	};

public:
	Papi(void)
	{
		_texture[0].loadFromFile("ressources/papi.png");
		_sprite[0].setTexture(_texture[0]);
		_texture[1].loadFromFile("ressources/papi1.png");
		_sprite[1].setTexture(_texture[1]);
		_texture[2].loadFromFile("ressources/papi2.png");
		_sprite[2].setTexture(_texture[2]);
		_texture[3].loadFromFile("ressources/papi3.png");
		_sprite[3].setTexture(_texture[3]);
		_texture[4].loadFromFile("ressources/papi4.png");
		_sprite[4].setTexture(_texture[4]);
		_texture[5].loadFromFile("ressources/papi5.png");
		_sprite[5].setTexture(_texture[5]);
		_texture[6].loadFromFile("ressources/papi6.png");
		_sprite[6].setTexture(_texture[6]);
		for (int it = 0; it < 7; ++it)
		{
			_sprite[it].setPosition(70, 100);
			_sprite[it].setScale(0.7f, 0.7f);
		}
		_frame = 0;
	}
	~Papi(void) {}

	void	update(sf::RenderWindow &window)
	{
		sf::Vector2f pos = _sprite[_frame].getPosition();
		switch (_direction)
		{
		case Papi::Direction::Left:
			++_frame;
			if (_frame > 6)
				_frame = 1;
			pos.x -= 6;
			if (pos.x < 0)
				pos.x = 0;
			break;
		case Papi::Direction::Right:
			--_frame;
			if (_frame < 1)
				_frame = 6;
			pos.x += 6;
			if (pos.x > 1100 - _texture[_frame].getSize().x)
				pos.x = 1100.0f - _texture[_frame].getSize().x;
			break;
		default:
			_frame = 0;
		};
		_sprite[_frame].setPosition(pos);
		_direction = None;
		window.draw(_sprite[_frame]);
	}

	void	setDirection(Papi::Direction direction) {_direction = direction;}

	sf::Vector2f	getPosition(void) const { return (_sprite[_frame].getPosition()); }
	sf::Vector2u	getSize(void) const { return (_texture[_frame].getSize()); }

private:
	Direction	_direction;

	sf::Texture	_texture[7];
	sf::Sprite	_sprite[7];
	int			_frame;
};