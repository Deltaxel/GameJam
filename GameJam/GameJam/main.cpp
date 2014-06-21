#include <cstdlib>
#include <iostream>
#include <deque>

#include "SFML/Graphics.hpp"
#include "fmod.hpp"

#include "Pigeon.hpp"
#include "HUD.hpp"
#include "Papi.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 768, 32), "Mettre ici le nom du jeu", Style::Close | Style::Titlebar);

	Texture image, sky, clouds, buildings, img, pigeon, play, quit, credit;
	Sprite hero, sSky, sClouds, sBuildings, sPlay, sQuit, sCredit;
	HUD	hud;
	Papi papi;
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

	if (sky.loadFromFile("sky.jpg") == 0
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
	FMOD::System *system;
    FMOD::Sound *musique;
    int resultat;

    FMOD::System_Create(&system);

    system->init(1, FMOD_INIT_NORMAL, NULL);

    resultat = system->createSound("music.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
    if (resultat != FMOD_OK)
    {
        std::cerr << "Impossible de lire le fichier mp3" << std::endl;
        return EXIT_FAILURE;
    }
	
	system->playSound(FMOD_CHANNEL_FREE, musique, 0, NULL);
	sPlay.setTexture(play);
	sPlay.setPosition(300, 100);
	sQuit.setTexture(quit);
	sQuit.setPosition(300, 300);
	sCredit.setTexture(credit);
	sCredit.setPosition(300, 500);
	FloatRect rPlay(300, 100, play.getSize().x, play.getSize().y), rQuit(300, 500, quit.getSize().x, quit.getSize().y),
			  rCredit(300, 300, credit.getSize().x, credit.getSize().y);
	sSky.setTexture(sky);
	sSky.setPosition(0, 0);
	sClouds.setTexture(clouds);
	sClouds.setPosition(0, 0);
	sBuildings.setTexture(buildings);
	sBuildings.setPosition(0, 0);

	Clock clock;
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
			papi.setDirection(Papi::Left);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			papi.setDirection(Papi::Right);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (down)
			{
				Spoop.push_back(new Sprite);
				Spoop.back()->setPosition(papi.getPosition().x + (papi.getSize().x / 2) - 50, papi.getPosition().y + 100);
				Spoop.back()->setTexture(img);
				Spoop.back()->setScale(0.2f, 0.2f);
				ok.push_back(true);
			}
				down = false;		
		}
		window.clear();
		window.draw(sSky);
		window.draw(sClouds);
		window.draw(sBuildings);
		papi.update(window);
		hud.update(window);

		unsigned int i;
		for (i = 0; i < Spoop.size(); ++i)
		{
			if (i == Spoop.size() - 1 && Spoop[i]->getPosition().y > papi.getPosition().y + 400)
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
		if (clock.getElapsedTime().asSeconds() > 175)
			system->close();
		window.display();
	}
    return EXIT_SUCCESS;
}