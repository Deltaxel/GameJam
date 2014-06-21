#include <cstdlib>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 768, 32), "Mettre ici le nom du jeu", Style::Close | Style::Titlebar);
	Texture image, img;
	Sprite hero;
	bool down = true;
	std::vector<Sprite *> Spoop;
	std::vector<bool>  ok;

	window.setFramerateLimit(60);
	if (!image.loadFromFile("hero.jpg") || !img.loadFromFile("poop.jpg"))
	{
		std::cerr << "Load image faild" << std::endl;
		return EXIT_FAILURE;
	}
	else
	{
		hero.setTexture(image);
	}
	hero.setPosition(50, 50);
	hero.scale(0.2,0.2);
	while (window.isOpen())
    {
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
		window.draw(hero);

		unsigned int i;
		for (i = 0; i < Spoop.size(); ++i)
		{
			if (i == Spoop.size() - 1 && Spoop[i]->getPosition().y > hero.getPosition().y + 250)
				down = true;
			if (!ok[i])
			{
				Spoop.erase(Spoop.begin() + i);
				ok.erase(ok.begin() + i);
			}
			else
			{
				window.draw(*Spoop[i]);
				if (Spoop[i]->getPosition().y + 26 < 768)
					Spoop[i]->setPosition(Spoop[i]->getPosition().x, Spoop[i]->getPosition().y + 6);
				else
				{
					Spoop[i]->setPosition(Spoop[i]->getPosition().x, 768);
					ok[i] = false;
				}
			}
		}
		window.display();
	}
    return EXIT_SUCCESS;
}