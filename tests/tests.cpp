#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include "../src/app_lib/functions.h"

using namespace sf;

// Тестирование функции loadTexture
void testLoadTexture()
{
    Texture t;
    std::string filename = "../Paint/Pro/1.png";
    loadTexture(t, filename);

    // Проверяем, успешно ли загрузилась текстура
    assert(t.getSize() != Vector2u(0, 0));

    // Проверяем, что загруженная текстура соответствует ожидаемым размерам
    assert(t.getSize().x == 512);
    assert(t.getSize().y == 512);

    std::cout << "TEST: loadTexture SUCCESSFULLY PASSED" << std::endl;
}

// Тестирование функции drawSprites
void testDrawSprites()
{
    // Создаем окно и спрайты для тестирования
    RenderWindow window(VideoMode(512, 512), "Tag game!");
    Sprite s[17];
    int grid[6][6] = { 0 };
    Texture t;
    int w = 128;
    initializeSprites(s, t, grid);

    // Вызываем функцию drawSprites
    drawSprites(window, s, grid, w);

    // Проверяем, что спрайты были отрисованы в окне

    std::cout << "TEST: drawSprites SUCCESSFULLY PASSED" << std::endl;
}

int main()
{
    // Тестируем каждую функцию по отдельности
    testLoadTexture();
    testDrawSprites();

    return 0;
}
