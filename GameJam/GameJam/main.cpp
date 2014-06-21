#include <cstdlib>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 768, 32), "Mettre ici le nom du jeu", Style::Close | Style::Titlebar);
	Texture image;
	Sprite hero;

	if (!image.loadFromFile("hero.jpg"))
	{
		std::cerr << "Load image faild" << std::endl;
		return EXIT_FAILURE;
	}
	else
		hero.setTexture(image);
	hero.setPosition(100, 300);
	hero.scale(0.2,0.2);
	while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
		window.clear();
		window.draw(hero);
		window.display();
    }
    return EXIT_SUCCESS;
}