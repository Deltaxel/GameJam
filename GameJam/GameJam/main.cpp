#include <cstdlib>
#include <iostream>
#include <deque>
#include <list>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "fmod.hpp"

#include "Pigeon.hpp"
#include "HUD.hpp"
#include "Papi.hpp"
#include "Caca.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 768, 32), "EDGY BOBY", Style::Close | Style::Titlebar);

	Texture sky, clouds, buildings, ground, end, gui, credit;
	Sprite sSky, sClouds, sBuildings, sGround, sEnd, sGui, sCredit;
	HUD	hud;
	bool isr = false;
	Papi papi;
	Font font;
	Text text;
	bool down = true;
	bool guiOk = true;
	std::list<Caca *> sPoop;
	std::list<Pigeon *> sPigeon;
	int score = 0;

	window.setFramerateLimit(60);

	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);
	sPigeon.push_back(new Pigeon);

	if (sky.loadFromFile("ressources/background.png") == 0
		|| clouds.loadFromFile("ressources/clouds.png") == 0
		|| buildings.loadFromFile("ressources/building.png") == 0
		|| ground.loadFromFile("ressources/floor.png") == 0
		|| font.loadFromFile("ressources/font.ttf") == 0
		|| end.loadFromFile("ressources/end.png") == 0
		|| gui.loadFromFile("ressources/interface.png") == 0
		|| credit.loadFromFile("ressources/credits.png") == 0)
	{
		std::cerr << "Load image faild" << std::endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}
	FMOD::System *system;
    FMOD::Sound *musique;
    int resultat;

    FMOD::System_Create(&system);

    system->init(1, FMOD_INIT_NORMAL, NULL);

    resultat = system->createSound("ressources/music.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
    if (resultat != FMOD_OK)
    {
        std::cerr << "Impossible de lire le fichier mp3" << std::endl;
		return EXIT_FAILURE;
    }
	
	system->playSound(FMOD_CHANNEL_FREE, musique, 0, NULL);
	sEnd.setTexture(end);
	sEnd.setPosition(0,0);
	sEnd.setScale(0.5, 0.5);
	sCredit.setTexture(credit);
	sCredit.setPosition(0,0);
	bool Bcredit = false;
	sGui.setTexture(gui);
	sGui.setPosition(0,0);
	FloatRect rPlay(263, 617, 240, 70), rQuit(1090, 741, 240, 70),
			  rCredit(261, 733, 240, 70);
	sSky.setTexture(sky);
	sSky.setPosition(0, 0);
	sSky.setScale(0.5,0.5);
	sClouds.setTexture(clouds);
	sClouds.setPosition(0, 0);
	sClouds.setScale(0.5,0.5);
	sBuildings.setTexture(buildings);
	sBuildings.setPosition(0, 0);
	sBuildings.setScale(0.5,0.5);
	sGround.setTexture(ground);
	sGround.setPosition(0, 745);
	text.setFont(font);
	text.setCharacterSize(60);
	text.setPosition(950, 640);
	text.setColor(sf::Color::Red);
	text.setString("0");
	int ret = 0;

	Clock clock;
	while (window.isOpen())
    {
		Event event;
		while (guiOk)
		{
			Vector2i mouse = Mouse::getPosition();
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					exit(0);
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left) == false)
				isr = false;
			if (rPlay.contains(window.mapPixelToCoords(mouse)) && Mouse::isButtonPressed(Mouse::Left))
			{
				guiOk = false;
				break ;
			}
			if (rQuit.contains(window.mapPixelToCoords(mouse)) && Mouse::isButtonPressed(Mouse::Left))
			{
				if (Bcredit == false && isr == false)
				{
					window.close();
					exit(0);
				}
				else
				{
					Bcredit = false;
					isr = true;
				}
			}
			if (rCredit.contains(window.mapPixelToCoords(mouse)) && Mouse::isButtonPressed(Mouse::Left))
				Bcredit = true;
			window.clear();
			if (!Bcredit)
				window.draw(sGui);
			else
				window.draw(sCredit);
			window.display();
		}
		std::ostringstream ss;
        while (window.pollEvent(event))
        {
			switch (event.type)
			{
				case Event::Closed:
					window.close();
					exit(0);
					break;
				case Event::KeyPressed:
					switch (event.key.code)
					{
						case Keyboard::Escape:
							window.close();
							exit(0);
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
				std::ostringstream ss;
				sPoop.push_back(new Caca(papi));
				ret = hud.clicked();
			}
				down = false;		
		}
		window.clear();
		window.draw(sSky);
		window.draw(sClouds);
		window.draw(sBuildings);
		window.draw(sGround);
		hud.update(window);
		papi.update(window);
		window.draw(text);

		unsigned long int	i = 1;
		auto it = sPoop.begin();
		while (it != sPoop.end())
		{
			if (i == sPoop.size() && (*it)->getPosition().y > 400)
				down = true;
			(*it)->update(window);
			if ((*it)->isAlive())
				++it;
			else
			{
				delete (*it);
				it = sPoop.erase(it);
			}
			++i;
		}
		for (auto it = sPigeon.begin(); it != sPigeon.end(); ++it)
			(*it)->update(window, sPoop, ret, score);
		ss << score;
		text.setString(ss.str());
		if (clock.getElapsedTime().asSeconds() > 175)
		{
			window.draw(sEnd);
			std::string toto("Your score is :\n      " + ss.str() + " / 3850\n    Press Echap");
			text.setString(toto);
			text.setCharacterSize(90);
			text.setPosition(300, 250);
			window.draw(text);
			system->close();
		}
		window.display();
	}
	exit(0);
    return EXIT_SUCCESS;
}