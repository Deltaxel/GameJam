#include <cstdlib>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 768, 32), "Mettre ici le nom du jeu", Style::Close | Style::Titlebar);
	Texture image, sky, clouds, buildings;
	Sprite hero, sSky, sClouds, sBuildings;

	if (image.loadFromFile("hero.jpg") == 0
		|| sky.loadFromFile("sky.jpg") == 0
		|| clouds.loadFromFile("clouds.png") == 0
		|| buildings.loadFromFile("buildings.png") == 0)
	{
		std::cerr << "Load image faild" << std::endl;
		return EXIT_FAILURE;
	}
	hero.setTexture(image);
	hero.setPosition(100, 300);
	hero.scale(0.2,0.2);
	sSky.setTexture(sky);
	sSky.setPosition(0, 0);
	sSky.scale(0, 0);
	sClouds.setTexture(clouds);
	sClouds.setPosition(0, 0);
	sClouds.scale(0, 0);
	sBuildings.setTexture(buildings);
	sBuildings.setPosition(0, 0);
	sBuildings.scale(0, 0);
	while (window.isOpen())
    {
		sClouds.setPosition((sClouds.getPosition().x + 1) % 1100, 0);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
		window.clear();
		window.draw(sSky);
		window.draw(sClouds);
		window.draw(sBuildings);
		window.draw(hero);
		window.display();
    }
    return EXIT_SUCCESS;
}