#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main()
{
    srand(time(0));
    
    RenderWindow window(VideoMode(512, 512), "Tag game!");
    window.setFramerateLimit(60);

    Texture t;
    int a = rand() % 5 + 1;
    switch (a)
    {
    case 1:
        t.loadFromFile("C:/Users/Андрей/Desktop/Paint/Pro/1.png");
        break;
    case 2:
        t.loadFromFile("C:/Users/Андрей/Desktop/Paint/Pro/2.png");
        break;
    case 3:
        t.loadFromFile("C:/Users/Андрей/Desktop/Paint/Pro/3.png");
        break;
    case 4:
        t.loadFromFile("C:/Users/Андрей/Desktop/Paint/Pro/4.png");
        break;
    case 5:
        t.loadFromFile("C:/Users/Андрей/Desktop/Paint/Pro/5.png");
        break;
    }
}