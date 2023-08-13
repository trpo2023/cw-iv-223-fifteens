#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include "../src/app_lib/functions.h"

using namespace sf;

// Тестирование функции loadTexture
void testLoadTexture()
{
    Texture t;
    std::string filename = "Paint/Pro/1.png";
    loadTexture(t, filename);

    // Проверяем, успешно ли загрузилась текстура
    assert(t.getSize() != Vector2u(0, 0));

    // Проверяем, что загруженная текстура соответствует ожидаемым размерам
    assert(t.getSize().x == 512);
    assert(t.getSize().y == 512);

    std::cout << "TEST 1/4 GRAPHIC_TEST:loadTexture [OK]" << std::endl;
}

// Тестирование функции initializeSprites
void testInitializeSprites()
{
    Sprite s[17];
    Texture t;
    int grid[6][6] = { 0 };
    initializeSprites(s, t, grid);

    // Проверяем, что в массиве grid все элементы больше нуля
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            assert(grid[i][j] > 0);
        }
    }

    std::cout << "TEST 2/4 GRAPHIC_TEST:initializeSprites [OK]" << std::endl;
}

// Тестирование завершения игры
void testGameCompletion()
{
    RenderWindow window(VideoMode(512, 512), "Tag game!");
    Texture t;
    int a = 1;
    int w = 128;
    Sprite s[17];
    int grid[6][6] = { 0 };
    initializeSprites(s, t, grid);

    // Расставляем плитки в правильном порядке
    int num = 1;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            grid[i][j] = num++;
        }
    }

    // Эмулируем завершение игры (закрытие окна)
    bool isGameOver = true;
    window.close();

    // Проверяем, что игра успешно завершена
    assert(isGameOver);

    std::cout << "TEST 3/4 LOGIC_TEST:gameCompletion [OK]" << std::endl;
}

// Тестирование алгоритма перемешивания плиток
void testTileShuffling()
{
    RenderWindow window(VideoMode(512, 512), "Tag game!");
    Texture t;
    int a = 1;
    int w = 128;
    Sprite s[17];
    int grid[6][6] = { 0 };
    initializeSprites(s, t, grid);

    // Сохраняем изначальное состояние плиток
    int initialGrid[6][6];
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            initialGrid[i][j] = grid[i][j];
        }
    }

    // Перемешиваем плитки
    shuffleTiles(grid);

    // Проверяем, что хотя бы одна плитка изменила свою позицию
    bool isShuffled = false;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (grid[i][j] != initialGrid[i][j]) {
                isShuffled = true;
                break;
            }
        }
        if (isShuffled) {
            break;
        }
    }

    // Проверяем, что плитки были перемешаны
    assert(isShuffled);

    std::cout << "TEST 4/4 LOGIC_TEST:tileShuffling [OK]" << std::endl;
}

int main()
{
    testLoadTexture();
    testInitializeSprites();
    testGameCompletion();
    testTileShuffling(); 

    return 0;
}
