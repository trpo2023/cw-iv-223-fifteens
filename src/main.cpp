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
        t.loadFromFile("C:/Users/Данила/Desktop/Paint/Pro/1.png");
        break;
    case 2:
        t.loadFromFile("C:/Users/Данила/Desktop/Paint/Pro/2.png");
        break;
    case 3:
        t.loadFromFile("C:/Users/Данила/Desktop/Paint/Pro/3.png");
        break;
    case 4:
        t.loadFromFile("C:/Users/Данила/Desktop/Paint/Pro/4.png");
        break;
    case 5:
        t.loadFromFile("C:/Users/Данила/Desktop/Paint/Pro/5.png");
        break;
    }
    Sprite s[17];
    int w = 128;
    int grid[6][6] = { 0 };
    int n = 0;
    for (int i=0; i<4; i++)
        for (int j = 0; j < 4; j++) {
            n++;
            s[n].setTexture(t);
            s[n].setTextureRect(IntRect(i * w, j * w, w, w));
            grid[i + 1][j + 1] = n;
        }
}