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
	RenderWindow window(VideoMode(1100, 768, 32), "Mettre ici le nom du jeu", Style::Close | Style::Titlebar);

	Texture sky, clouds, buildings, play, quit, credit, ground;
	Sprite sSky, sClouds, sBuildings, sPlay, sQuit, sCredit, sGround;
	HUD	hud;
	Papi papi;
	Font font;
	Text text;
	bool down = true;
	bool gui = true;
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

	if (sky.loadFromFile("fond.png") == 0
		|| clouds.loadFromFile("nuages.png") == 0
		|| buildings.loadFromFile("batiment.png") == 0
		|| play.loadFromFile("play.png") == 0
		|| quit.loadFromFile("play.png") == 0
		|| credit.loadFromFile("play.png") == 0
		|| ground.loadFromFile("floor.png") == 0
		|| font.loadFromFile("font.ttf") == 0)
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
	text.setPosition(980, 700);
	text.setColor(sf::Color::Red);
	text.setString("0");
	int ret = 0;

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
		std::ostringstream ss;
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
			system->close();
		window.display();
	}
    return EXIT_SUCCESS;
}