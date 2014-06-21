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

private:
		sf::Texture _text;
		sf::Sprite _sprite;

public:
	class Button;

public:
	HUD(void)
	{
		sf::Clock clock;
		
		_text.loadFromFile("test3.png");
		_sprite.setTexture(_text);
		_sprite.setPosition(210,50);
		_sprite.scale(0.9,0.9);

		_buttons.push_back(new HUD::Button(11.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(13, Button::Red, clock));
		_buttons.push_back(new HUD::Button(14, Button::Red, clock));
		_buttons.push_back(new HUD::Button(15, Button::Red, clock));
		_buttons.push_back(new HUD::Button(16.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(17, Button::Red, clock));
		_buttons.push_back(new HUD::Button(18, Button::Red, clock));
		_buttons.push_back(new HUD::Button(19, Button::Red, clock));
		_buttons.push_back(new HUD::Button(20.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(21, Button::Red, clock));
		_buttons.push_back(new HUD::Button(21.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(22, Button::Red, clock));
		_buttons.push_back(new HUD::Button(24, Button::Red, clock));
		_buttons.push_back(new HUD::Button(27, Button::Red, clock));
		_buttons.push_back(new HUD::Button(28, Button::Red, clock));
		_buttons.push_back(new HUD::Button(29, Button::Red, clock));
		_buttons.push_back(new HUD::Button(30, Button::Red, clock));
		_buttons.push_back(new HUD::Button(30.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(31, Button::Red, clock));
		_buttons.push_back(new HUD::Button(32, Button::Red, clock));
		_buttons.push_back(new HUD::Button(32.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(33, Button::Red, clock));
		_buttons.push_back(new HUD::Button(34, Button::Red, clock));
		_buttons.push_back(new HUD::Button(35, Button::Red, clock));
		_buttons.push_back(new HUD::Button(35.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(36, Button::Red, clock));
		_buttons.push_back(new HUD::Button(40, Button::Red, clock));
		_buttons.push_back(new HUD::Button(40.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(41, Button::Red, clock));
		_buttons.push_back(new HUD::Button(42, Button::Red, clock));
		_buttons.push_back(new HUD::Button(42.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(43, Button::Red, clock));
		_buttons.push_back(new HUD::Button(45, Button::Red, clock));
		_buttons.push_back(new HUD::Button(45.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(46.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(47, Button::Red, clock));
		_buttons.push_back(new HUD::Button(49, Button::Red, clock));
		_buttons.push_back(new HUD::Button(51, Button::Red, clock));
		_buttons.push_back(new HUD::Button(51.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(52, Button::Red, clock));
		_buttons.push_back(new HUD::Button(52.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(53, Button::Red, clock));
		_buttons.push_back(new HUD::Button(53.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(54.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(55.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(56, Button::Red, clock));
		_buttons.push_back(new HUD::Button(60, Button::Red, clock));
		_buttons.push_back(new HUD::Button(61, Button::Red, clock));
		_buttons.push_back(new HUD::Button(61.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(62, Button::Red, clock));
		_buttons.push_back(new HUD::Button(62.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(63, Button::Red, clock));
		_buttons.push_back(new HUD::Button(64, Button::Red, clock));
		_buttons.push_back(new HUD::Button(65, Button::Red, clock));
		_buttons.push_back(new HUD::Button(65.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(67, Button::Red, clock));
		_buttons.push_back(new HUD::Button(68, Button::Red, clock));
		_buttons.push_back(new HUD::Button(68.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(69.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(70, Button::Red, clock));
		_buttons.push_back(new HUD::Button(71, Button::Red, clock));
		_buttons.push_back(new HUD::Button(71.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(72, Button::Red, clock));
		_buttons.push_back(new HUD::Button(74, Button::Red, clock));
		_buttons.push_back(new HUD::Button(75, Button::Red, clock));
		_buttons.push_back(new HUD::Button(75.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(76, Button::Red, clock));
		_buttons.push_back(new HUD::Button(77, Button::Red, clock));
		_buttons.push_back(new HUD::Button(78, Button::Red, clock));
		_buttons.push_back(new HUD::Button(78.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(79, Button::Red, clock));
		_buttons.push_back(new HUD::Button(82, Button::Red, clock));
		_buttons.push_back(new HUD::Button(82.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(83, Button::Red, clock));
		_buttons.push_back(new HUD::Button(84, Button::Red, clock));
		_buttons.push_back(new HUD::Button(85, Button::Red, clock));
		_buttons.push_back(new HUD::Button(86, Button::Red, clock));
		_buttons.push_back(new HUD::Button(86.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(87, Button::Red, clock));
		_buttons.push_back(new HUD::Button(87.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(89, Button::Red, clock));
		_buttons.push_back(new HUD::Button(90, Button::Red, clock));
		_buttons.push_back(new HUD::Button(91, Button::Red, clock));
		_buttons.push_back(new HUD::Button(92, Button::Red, clock));
		_buttons.push_back(new HUD::Button(92.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(93, Button::Red, clock));
		_buttons.push_back(new HUD::Button(93.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(94.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(95, Button::Red, clock));
		_buttons.push_back(new HUD::Button(96.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(97, Button::Red, clock));
		_buttons.push_back(new HUD::Button(98, Button::Red, clock));
		_buttons.push_back(new HUD::Button(98.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(99, Button::Red, clock));
		_buttons.push_back(new HUD::Button(100.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(101, Button::Red, clock));
		_buttons.push_back(new HUD::Button(101.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(102, Button::Red, clock));
		_buttons.push_back(new HUD::Button(103, Button::Red, clock));
		_buttons.push_back(new HUD::Button(104, Button::Red, clock));
		_buttons.push_back(new HUD::Button(104.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(105, Button::Red, clock));
		_buttons.push_back(new HUD::Button(106.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(107.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(108, Button::Red, clock));
		_buttons.push_back(new HUD::Button(108.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(109.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(110, Button::Red, clock));
		_buttons.push_back(new HUD::Button(115, Button::Red, clock));
		_buttons.push_back(new HUD::Button(116, Button::Red, clock));
		_buttons.push_back(new HUD::Button(117.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(118, Button::Red, clock));
		_buttons.push_back(new HUD::Button(119, Button::Red, clock));
		_buttons.push_back(new HUD::Button(119.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(120, Button::Red, clock));
		_buttons.push_back(new HUD::Button(121, Button::Red, clock));
		_buttons.push_back(new HUD::Button(122, Button::Red, clock));
		_buttons.push_back(new HUD::Button(124, Button::Red, clock));
		_buttons.push_back(new HUD::Button(125, Button::Red, clock));
		_buttons.push_back(new HUD::Button(125.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(126, Button::Red, clock));
		_buttons.push_back(new HUD::Button(127, Button::Red, clock));
		_buttons.push_back(new HUD::Button(127.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(128, Button::Red, clock));
		_buttons.push_back(new HUD::Button(130, Button::Red, clock));
		_buttons.push_back(new HUD::Button(130.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(131, Button::Red, clock));
		_buttons.push_back(new HUD::Button(131.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(132, Button::Red, clock));
		_buttons.push_back(new HUD::Button(133, Button::Red, clock));
		_buttons.push_back(new HUD::Button(134, Button::Red, clock));
		_buttons.push_back(new HUD::Button(136, Button::Red, clock));
		_buttons.push_back(new HUD::Button(136.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(137, Button::Red, clock));
		_buttons.push_back(new HUD::Button(138, Button::Red, clock));
		_buttons.push_back(new HUD::Button(138.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(139, Button::Red, clock));
		_buttons.push_back(new HUD::Button(139.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(140, Button::Red, clock));
		_buttons.push_back(new HUD::Button(142, Button::Red, clock));
		_buttons.push_back(new HUD::Button(143, Button::Red, clock));
		_buttons.push_back(new HUD::Button(144, Button::Red, clock));
		_buttons.push_back(new HUD::Button(144.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(145, Button::Red, clock));
		_buttons.push_back(new HUD::Button(146, Button::Red, clock));
		_buttons.push_back(new HUD::Button(146.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(147, Button::Red, clock));
		_buttons.push_back(new HUD::Button(149, Button::Red, clock));
		_buttons.push_back(new HUD::Button(150, Button::Red, clock));
		_buttons.push_back(new HUD::Button(151.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(152, Button::Red, clock));
		_buttons.push_back(new HUD::Button(152.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(153, Button::Red, clock));
		_buttons.push_back(new HUD::Button(155, Button::Red, clock));
		_buttons.push_back(new HUD::Button(155.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(156, Button::Red, clock));
		_buttons.push_back(new HUD::Button(156.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(157, Button::Red, clock));
		_buttons.push_back(new HUD::Button(159, Button::Red, clock));
		_buttons.push_back(new HUD::Button(160, Button::Red, clock));
		_buttons.push_back(new HUD::Button(161, Button::Red, clock));
		_buttons.push_back(new HUD::Button(161.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(162.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(164, Button::Red, clock));
		_buttons.push_back(new HUD::Button(164.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(165, Button::Red, clock));
		_buttons.push_back(new HUD::Button(165.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(167, Button::Red, clock));
		_buttons.push_back(new HUD::Button(168, Button::Red, clock));
		_buttons.push_back(new HUD::Button(168.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(169, Button::Red, clock));
		_buttons.push_back(new HUD::Button(170, Button::Red, clock));
		_buttons.push_back(new HUD::Button(171, Button::Red, clock));
		_buttons.push_back(new HUD::Button(171.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(172, Button::Red, clock));
		_buttons.push_back(new HUD::Button(172.5, Button::Red, clock));
		_buttons.push_back(new HUD::Button(173, Button::Red, clock));
	}
	~HUD(void) {}

	HUD::WellPlay	update(sf::RenderWindow &window)
	{
		HUD::WellPlay	ret = None;

		window.draw(_sprite);
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
		if (_buttons.front()->getPosX() >= 185 && _buttons.front()->getPosX() <= 250)
			ret = HUD::WellPlay::Great;
		else if (_buttons.front()->getPosX() >= 251 && _buttons.front()->getPosX() <= 310)
			ret = HUD::WellPlay::Ok;
		delete _buttons.front();
		_buttons.erase(_buttons.begin());
		return (ret);
	}

public:
	std::list<HUD::Button *> _buttons;
	sf::Clock				_clock;
public:
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
		Button(float time, HUD::Button::Color color, sf::Clock &clock)
		{
			_time = time;
			switch (color)
			{
			case HUD::Button::Color::Blue:
				_texture.loadFromFile("BlueButton.png");
				break ;
			case HUD::Button::Color::Red:
				_texture.loadFromFile("RedButton.jpg");
				break;
			case HUD::Button::Color::Green:
				_texture.loadFromFile("GreenButton.png");
				break;
			case HUD::Button::Color::Yellow:
				_texture.loadFromFile("YellowButton.png");
				break;
			};
			_sprite.setTexture(_texture);
			_sprite.setScale(0.1f, 0.1f);
			_sprite.setPosition(200 * _time + 400, 50);
			_time += clock.getElapsedTime().asSeconds();
		}

		~Button(void) {}

		void	update(sf::RenderWindow &window)
		{
			_sprite.setPosition(_sprite.getPosition().x - 200.0f * _clock.getElapsedTime().asSeconds(), 50.0f);
			window.draw(_sprite);
			_clock.restart();
		}

		float	atTime(void) {return (_time);}
		float	getPosX() {return (_sprite.getPosition().x);}

	private:
		float		_time;
		sf::Texture	_texture;
		sf::Sprite	_sprite;
		sf::Clock	_clock;
	};
};