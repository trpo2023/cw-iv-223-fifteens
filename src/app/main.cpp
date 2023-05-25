#include "../app_lib/functions.h"
#include <SFML/Graphics.hpp>
#include <time.h>

int main()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(512, 512), "Tag game!");
    window.setFramerateLimit(60);

    sf::Texture t;
    int a = rand() % 5 + 1;
    switch (a) {
    case 1:
        loadTexture(t, "Paint/Pro/1.png");
        break;
    case 2:
        loadTexture(t, "Paint/Pro/2.png");
        break;
    case 3:
        loadTexture(t, "Paint/Pro/3.png");
        break;
    case 4:
        loadTexture(t, "Paint/Pro/4.png");
        break;
    case 5:
        loadTexture(t, "Paint/Pro/5.png");
        break;
    }

    sf::Sprite s[17];
    int w = 128;
    int grid[6][6] = {0};

    initializeSprites(s, t, grid);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    handleMouseClick(event.mouseButton, window, grid, s, a, w);
                }
            }
        }

        window.clear(sf::Color::White);
        drawSprites(window, s, grid, w);
        window.display();
    }

    return 0;
}
