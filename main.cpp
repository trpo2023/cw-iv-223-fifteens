#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main()
{
    srand(time(0));
    
    RenderWindow window(VideoMode(512, 512), "Tag game!");
    window.setFramerateLimit(60);
}