#define CTEST_MAIN
#include "../lib/thirdparty/ctest.h"
#include "../src/app_lib/functions.h"
#include <SFML/Graphics.hpp>

CTEST(GraphicTest, DrawSprites)
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tag game!");
    window.setFramerateLimit(60);

    sf::Texture t;
    loadTexture(t, "Paint/Pro/1.png");

    sf::Sprite s[17];
    int grid[6][6] = {0};
    initializeSprites(s, t, grid);

    // Вызовите drawSprites и убедитесь, что плитки отрисованы корректно
    drawSprites(window, s, grid, 128);

    // Проверьте, что плитки отрисованы в правильных позициях на окне
    int w = 128;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n = grid[i + 1][j + 1];
            int expectedX = i * w; // Ожидаемая позиция по x
            int expectedY = j * w; // Ожидаемая позиция по y
            sf::Vector2f spritePosition = s[n].getPosition();
            ASSERT_TRUE(
                    spritePosition.x == expectedX
                    && spritePosition.y == expectedY);
        }
    }
}

CTEST(GraphicTests, LoadTexture)
{
    sf::Texture t;
    loadTexture(t, "Paint/Pro/1.png");
    ASSERT_TRUE(
            t.getSize().x > 0
            && t.getSize().y > 0); // Проверка, что текстура не пуста
}

CTEST(FunctionTests, InitializeSprites)
{
    sf::Sprite s[17];
    int grid[6][6] = {0};
    sf::Texture t;
    initializeSprites(s, t, grid);

    // Проверка, что первый спрайт имеет не нулевую позицию и текстуру
    ASSERT_TRUE(s[1].getTexture() != nullptr);
}

CTEST(LogicTests, HandleMouseClick)
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tag game!");
    window.setFramerateLimit(60);

    sf::Texture t;
    loadTexture(t, "Paint/Pro/1.png");

    sf::Sprite s[17];
    int grid[6][6] = {0};
    initializeSprites(s, t, grid);

    sf::Event mouseEvent;
    mouseEvent.type = sf::Event::MouseButtonPressed;
    mouseEvent.mouseButton.button = sf::Mouse::Left;
    mouseEvent.mouseButton.x = 100;
    mouseEvent.mouseButton.y = 100;

    handleMouseClick(mouseEvent.mouseButton, window, grid, s, 16, 128);

    // Проверка, что позиция спрайта после щелчка изменилась
    ASSERT_TRUE(s[16].getPosition() == sf::Vector2f(0, 0));
}

CTEST(LogicTests, HandleKeyPress)
{
    sf::Sprite s[17];
    int grid[6][6] = {0};

    // Создайте начальное состояние grid и s
    // Например, установите некоторые плитки в начальное положение
    int originalX = 2; // Начальная позиция плитки по x
    int originalY = 2; // Начальная позиция плитки по y

    grid[originalX][originalY] = 1; // Плитка начинает с позиции (2, 2)

    // Проверьте, что при нажатии клавиши валидного направления плитки
    // перемещаются
    sf::Keyboard::Key keys[]
            = {sf::Keyboard::Up,
               sf::Keyboard::Down,
               sf::Keyboard::Left,
               sf::Keyboard::Right};
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    int aValue = 1; // Создайте переменную для хранения значения a

    for (int i = 0; i < 4; ++i) {
        handleKeyPress(
                keys[i],
                grid,
                s,
                aValue,
                128); // Передайте переменную aValue вместо временного значения

        int newX = originalX + dx[i]; // Конечная позиция плитки по x
        int newY = originalY + dy[i]; // Конечная позиция плитки по y

        // Проверьте, что плитки переместились правильно
        ASSERT_TRUE(
                grid[originalX][originalY]
                == 0); // Плитка была удалена из старой позиции
        ASSERT_TRUE(grid[newX][newY] == 1); // Плитка появилась в новой позиции

        // Обновите начальную позицию для следующей проверки
        originalX = newX;
        originalY = newY;
    }
}

int main(int argc, const char** argv)
{
    int result = ctest_main(argc, argv);
    return result;
}
