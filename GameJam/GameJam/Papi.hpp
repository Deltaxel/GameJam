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
		_sprite.setPosition(70, 100);
		_texture.loadFromFile("papi.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(0.7,0.7);
	}
	~Papi(void) {}

	void	update(sf::RenderWindow &window)
	{
		sf::Vector2f pos = _sprite.getPosition();
		switch (_direction)
		{
		case Papi::Direction::Left:
			pos.x -= 8;
			if (pos.x < 0)
				pos.x = 0;
			break ;
		case Papi::Direction::Right:
			pos.x += 8;
			if (pos.x > 1100 - _texture.getSize().x)
				pos.x = 1100.0f - _texture.getSize().x;
			break;
		};
		_sprite.setPosition(pos);
		_direction = None;
		window.draw(_sprite);
	}

	void	setDirection(Papi::Direction direction) {_direction = direction;}

	sf::Vector2f	getPosition(void) const { return (_sprite.getPosition()); }
	sf::Vector2u	getSize(void) const { return (_texture.getSize()); }

private:
	Direction	_direction;

	sf::Texture	_texture;
	sf::Sprite	_sprite;
};