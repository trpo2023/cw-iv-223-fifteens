#include "functions.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void loadTexture(sf::Texture& t, const std::string& filename)
{
    if (!t.loadFromFile(filename)) {
        std::cerr << "Failed to load texture from file: " << filename
                  << std::endl;
        exit(1);
    }
}

void initializeSprites(sf::Sprite s[], sf::Texture& t, int grid[][6])
{
    int w = 128;
    int n = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            n++;
            s[n].setTexture(t);
            s[n].setTextureRect(sf::IntRect(i * w, j * w, w, w));
            grid[i + 1][j + 1] = n;
        }
    }
}

void handleMouseClick(
        sf::Event::MouseButtonEvent mouseEvent,
        sf::RenderWindow& window,
        int grid[][6],
        sf::Sprite s[],
        int a,
        int w)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window);

    int x = pos.x / w + 1;
    int y = pos.y / w + 1;

    int dx = 0;
    int dy = 0;

    int b;
    if (a != 2 && a != 5)
        b = 16;
    else if (a == 2 || a == 5)
        b = 4;

    if (grid[x + 1][y] == b) {
        dx = 1;
        dy = 0;
    }
    if (grid[x - 1][y] == b) {
        dx = -1;
        dy = 0;
    }
    if (grid[x][y - 1] == b) {
        dx = 0;
        dy = -1;
    }
    if (grid[x][y + 1] == b) {
        dx = 0;
        dy = 1;
    }

    int n = grid[x][y];
    grid[x][y] = b;
    grid[x + dx][y + dy] = n;

    s[b].move(-dx * w, -dy * w);
    float speed = 16;
    for (int i = 0; i < w; i += speed) {
        s[n].move(speed * dx, speed * dy);
        window.draw(s[b]);
        window.draw(s[n]);
        window.display();
    }
}

void drawSprites(sf::RenderWindow& window, sf::Sprite s[], int grid[][6], int w)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n = grid[i + 1][j + 1];
            s[n].setPosition(i * w, j * w);
            window.draw(s[n]);
        }
    }
}
