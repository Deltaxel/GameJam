#pragma once

#include <list>

#include "SFML/Graphics.hpp"

class HUD
{
public:
	enum WellPlay
	{
		None,
		Fail,
		Ok,
		Great
	};

public:
	class Button;

public:
	HUD(void)
	{
		_buttons.push_back(new HUD::Button(5, Button::Red));
		_buttons.push_back(new HUD::Button(6, Button::Red));
		_buttons.push_back(new HUD::Button(7, Button::Red));
		_buttons.push_back(new HUD::Button(9, Button::Red));
	}
	~HUD(void) {}

	HUD::WellPlay	update(sf::RenderWindow &window)
	{
		HUD::WellPlay	ret = None;

		if (_buttons.empty())
			return (None);
		if (_clock.getElapsedTime().asSeconds() > _buttons.front()->atTime() + 1)
		{
			delete _buttons.front();
			_buttons.erase(_buttons.begin());
			ret = WellPlay::Fail;
		}
		for (auto it = _buttons.begin(); it != _buttons.end(); ++it)
			(*it)->update(window);
		return (ret);
	}

	HUD::WellPlay	clicked(void)
	{
		HUD::WellPlay	ret = HUD::WellPlay::Fail;

		if (_buttons.empty())
			return (None);
		if (_buttons.front()->atTime() - _clock.getElapsedTime().asSeconds() > 5)
			return (HUD::WellPlay::None);
		if (_buttons.front()->atTime() - _clock.getElapsedTime().asSeconds() < 0.1)
			ret = HUD::WellPlay::Great;
		else if (_buttons.front()->atTime() - _clock.getElapsedTime().asSeconds() < 0.5)
			ret = HUD::WellPlay::Ok;
		delete _buttons.front();
		_buttons.erase(_buttons.begin());
		return (ret);
	}

public:
	std::list<HUD::Button *> _buttons;
	sf::Clock				_clock;

private:
	class Button
	{
	public:
		enum Color
		{
			Blue,
			Red,
			Green,
			Yellow
		};

	public:
		Button(float time, HUD::Button::Color color)
		{
			_time = time;
			switch (color)
			{
			case HUD::Button::Color::Blue:
				_texture.loadFromFile("BlueButton.png");
				break ;
			case HUD::Button::Color::Red:
				_texture.loadFromFile("RedButton.png");
				break;
			case HUD::Button::Color::Green:
				_texture.loadFromFile("GreenButton.png");
				break;
			case HUD::Button::Color::Yellow:
				_texture.loadFromFile("YellowButton.png");
				break;
			};
			_sprite.setTexture(_texture);
			_sprite.setPosition(2 * _time + 1100, 50);
		}

		~Button(void) {}

		void	update(sf::RenderWindow &window)
		{
			_sprite.setPosition(_sprite.getPosition().x - 2 * _clock.getElapsedTime().asSeconds(), 50);
			window.draw(_sprite);
		}

		float	atTime(void) {return (_time);}

	private:
		float		_time;
		sf::Texture	_texture;
		sf::Sprite	_sprite;
		sf::Clock	_clock;
	};
};