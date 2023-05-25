#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>

void loadTexture(sf::Texture& t, const std::string& filename);
void initializeSprites(sf::Sprite s[], sf::Texture& t, int grid[][6]);
void handleMouseClick(
        sf::Event::MouseButtonEvent mouseEvent,
        sf::RenderWindow& window,
        int grid[][6],
        sf::Sprite s[],
        int a,
        int w);
void drawSprites(
        sf::RenderWindow& window, sf::Sprite s[], int grid[][6], int w);

#endif
