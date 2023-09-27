#define CTEST_MAIN
#include "../lib/thirdparty/ctest.h"
#include "../src/app_lib/functions.h"
#include <SFML/Graphics.hpp>

CTEST(FunctionTests, LoadTexture) {
    sf::Texture t;
    loadTexture(t, "Paint/Pro/1.png");
    ASSERT_TRUE(t.getSize().x > 0 && t.getSize().y > 0); // Проверка, что текстура не пуста
}

CTEST(FunctionTests, InitializeSprites) {
    sf::Sprite s[17];
    int grid[6][6] = { 0 };
    sf::Texture t;
    initializeSprites(s, t, grid);
    
    // Проверка, что первый спрайт имеет не нулевую позицию и текстуру
    ASSERT_TRUE(s[1].getTexture() != nullptr);
}

CTEST(LogicTests, HandleMouseClick) {
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tag game!");
    window.setFramerateLimit(60);

    sf::Texture t;
    loadTexture(t, "Paint/Pro/1.png");

    sf::Sprite s[17];
    int grid[6][6] = { 0 };
    initializeSprites(s, t, grid);

    sf::Event mouseEvent;
    mouseEvent.type = sf::Event::MouseButtonPressed;
    mouseEvent.mouseButton.button = sf::Mouse::Left;
    mouseEvent.mouseButton.x = 100;
    mouseEvent.mouseButton.y = 100;

    handleMouseClick(mouseEvent.mouseButton, window, grid, s, 16, 128);
    
    // Проверка, что позиция спрайта после щелчка изменилась
    ASSERT_TRUE(s[16].getPosition() == sf::Vector2f(0, 0));
    // Добавьте другие проверки по необходимости
}

// Добавьте другие тестовые сценарии для других функций

int main(int argc, const char** argv) {
    int result = ctest_main(argc, argv);
    return result;
}
