#include <cstdlib>
#include <iostream>
#include <deque>

#include <SFML/Graphics.hpp>

#include "Pigeon.hpp"
#include "HUD.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 768, 32), "Mettre ici le nom du jeu", Style::Close | Style::Titlebar);
	Texture image, sky, clouds, buildings, img, pigeon, play, quit, credit;
	Sprite hero, sSky, sClouds, sBuildings, sPlay, sQuit, sCredit;
	HUD	hud;
	bool down = true;
	bool gui = true;
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

	if (image.loadFromFile("papi.png") == 0
		|| sky.loadFromFile("sky.jpg") == 0
		|| clouds.loadFromFile("clouds.png") == 0
		|| buildings.loadFromFile("buildings.png") == 0
		|| img.loadFromFile("poop.jpg") == 0
		|| pigeon.loadFromFile("pigeon.png") == 0
		|| play.loadFromFile("play.png") == 0
		|| quit.loadFromFile("play.png") == 0
		|| credit.loadFromFile("play.png") == 0)
	{
		std::cerr << "Load image faild" << std::endl;
		return EXIT_FAILURE;
	}
	sPlay.setTexture(play);
	sPlay.setPosition(300, 100);
	sQuit.setTexture(quit);
	sQuit.setPosition(300, 300);
	sCredit.setTexture(credit);
	sCredit.setPosition(300, 500);
	FloatRect rPlay(300, 100, play.getSize().x, play.getSize().y), rQuit(300, 500, quit.getSize().x, quit.getSize().y),
			  rCredit(300, 300, credit.getSize().x, credit.getSize().y);
	hero.setTexture(image);
	hero.setPosition(50, 50);
	hero.scale(0.75,0.75);
	sSky.setTexture(sky);
	sSky.setPosition(0, 0);
	sClouds.setTexture(clouds);
	sClouds.setPosition(0, 0);
	sBuildings.setTexture(buildings);
	sBuildings.setPosition(0, 0);
	
	while (window.isOpen())
    {
		Event event;
		//while (gui)
		//{
		//	Vector2i mouse = Mouse::getPosition();
		//	while (window.pollEvent(event))
		//	{
		//		if (event.type == Event::Closed)
		//			window.close();
		//	}
		//	if (rPlay.contains(window.mapPixelToCoords(mouse)))
		//		gui = false;
		//	if (rQuit.contains(window.mapPixelToCoords(mouse)))
		//		window.close();
		//	window.clear();
		//	window.draw(sPlay);
		//	window.draw(sQuit);
		//	window.draw(sCredit);
		//	window.display();
		//}
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
		sClouds.setPosition(((int)sClouds.getPosition().x - 1) % 1100, 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (hero.getPosition().x - 5 < 0)
				hero.setPosition(0, hero.getPosition().y);
			else
				hero.setPosition(hero.getPosition().x - 5, hero.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (hero.getPosition().x + image.getSize().x - 50 >= 1100)
				hero.setPosition(1100 - image.getSize().x + 50, hero.getPosition().y);
			else
				hero.setPosition(hero.getPosition().x + 5, hero.getPosition().y);		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (down)
			{
				Spoop.push_back(new Sprite);
				Spoop.back()->setPosition(hero.getPosition().x + (image.getSize().x / 2) - 50, hero.getPosition().y + 100);
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
		hud.update(window);

		unsigned int i;
		for (i = 0; i < Spoop.size(); ++i)
		{
			if (i == Spoop.size() - 1 && Spoop[i]->getPosition().y > hero.getPosition().y + 400)
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