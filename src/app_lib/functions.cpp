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

void handleKeyPress(
        sf::Keyboard::Key key, int grid[][6], sf::Sprite s[], int& a, int w)
{
    int dx = 0;
    int dy = 0;

    switch (key) {
    case sf::Keyboard::Up:
        dy = -1;
        break;
    case sf::Keyboard::Down:
        dy = 1;
        break;
    case sf::Keyboard::Left:
        dx = -1;
        break;
    case sf::Keyboard::Right:
        dx = 1;
        break;
    default:
        return;
    }

    int x, y;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (grid[i][j] == a) {
                x = i;
                y = j;
                break;
            }
        }
    }

    int new_x = x + dx;
    int new_y = y + dy;

    if (new_x >= 1 && new_x <= 4 && new_y >= 1 && new_y <= 4) {
        int b = grid[new_x][new_y];
        grid[new_x][new_y] = a;
        grid[x][y] = b;

        s[a].move(w * dx, w * dy);
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

void shuffleTiles(int grid[][6])
{
    int n = 16;
    while (n > 1) {
        int i = rand() % 4 + 1;
        int j = rand() % 4 + 1;
        int x = grid[i][j];
        int ii = rand() % 4 + 1;
        int jj = rand() % 4 + 1;
        grid[i][j] = grid[ii][jj];
        grid[ii][jj] = x;
        n--;
    }
}
