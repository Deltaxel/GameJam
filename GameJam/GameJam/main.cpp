#include <cstdlib>
#include <iostream>
#include <deque>

#include <SFML/Graphics.hpp>

#include "Pigeon.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 768, 32), "Mettre ici le nom du jeu", Style::Close | Style::Titlebar);
	Texture image, sky, clouds, buildings, img, pigeon;
	Sprite hero, sSky, sClouds, sBuildings;
	bool down = true;
	std::vector<Sprite *> Spoop;
	std::vector<bool>  ok;
	std::vector<Pigeon *> Spigeon;

	window.setFramerateLimit(60);

	Spigeon.push_back(new Pigeon);
	Spigeon.push_back(new Pigeon);
	Spigeon.push_back(new Pigeon);
	Spigeon.push_back(new Pigeon);
	Spigeon.push_back(new Pigeon);
	Spigeon.push_back(new Pigeon);

	if (image.loadFromFile("hero.jpg") == 0
		|| sky.loadFromFile("sky.jpg") == 0
		|| clouds.loadFromFile("clouds.png") == 0
		|| buildings.loadFromFile("buildings.png") == 0
		|| img.loadFromFile("poop.jpg") == 0
		|| pigeon.loadFromFile("pigeon.png") == 0)
	{
		std::cerr << "Load image faild" << std::endl;
		return EXIT_FAILURE;
	}
	hero.setTexture(image);
	hero.setPosition(50, 50);
	hero.scale(0.2,0.2);
	sSky.setTexture(sky);
	sSky.setPosition(0, 0);
	sClouds.setTexture(clouds);
	sClouds.setPosition(0, 0);
	sBuildings.setTexture(buildings);
	sBuildings.setPosition(0, 0);
	
	while (window.isOpen())
    {
		sClouds.setPosition(((int)sClouds.getPosition().x - 1) % 1100, 0);
        Event event;
        while (window.pollEvent(event))
        {
			switch (event.type)
			{
				case Event::Closed:
					window.close();
					break;
				case Event::KeyPressed:
					switch (event.key.code)
					{
						case Keyboard::Escape:
							window.close();
							break;
						default:
							break;
					}
				default:
					break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (hero.getPosition().x - 5 < 0)
				hero.setPosition(0, hero.getPosition().y);
			else
				hero.setPosition(hero.getPosition().x - 5, hero.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (hero.getPosition().x + 110 >= 1100)
				hero.setPosition(1100 - 110, hero.getPosition().y);
			else
				hero.setPosition(hero.getPosition().x + 5, hero.getPosition().y);		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (down)
			{
				Spoop.push_back(new Sprite);
				Spoop.back()->setPosition(hero.getPosition().x + 40, hero.getPosition().y + 160);
				Spoop.back()->setTexture(img);
				Spoop.back()->setScale(0.2,0.2);
				ok.push_back(true);
			}
				down = false;		
		}
		window.clear();
		window.draw(sSky);
		window.draw(sClouds);
		window.draw(sBuildings);
		window.draw(hero);

		unsigned int i;
		for (i = 0; i < Spoop.size(); ++i)
		{
			if (i == Spoop.size() - 1 && Spoop[i]->getPosition().y > hero.getPosition().y + 650)
				down = true;
			if (!ok[i])
			{
				Spoop.erase(Spoop.begin() + i);
				ok.erase(ok.begin() + i);
			}
			else
			{
				window.draw(*Spoop[i]);
				if (Spoop[i]->getPosition().y + 35 < 768)
					Spoop[i]->setPosition(Spoop[i]->getPosition().x, Spoop[i]->getPosition().y + 15);
				else
				{
					Spoop[i]->setPosition(Spoop[i]->getPosition().x, 768);
					ok[i] = false;
				}
			}
		}
		for (auto it = Spigeon.begin(); it != Spigeon.end(); ++it)
			(*it)->update(window, Spoop);
		window.display();
	}
    return EXIT_SUCCESS;
}