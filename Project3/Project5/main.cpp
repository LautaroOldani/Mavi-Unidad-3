#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {

    RenderWindow window(VideoMode(800, 600), "Ventana con Fondo");

   
    Texture texture_fondo;
    if (!texture_fondo.loadFromFile("fondo.jpg")) {
        return -1;
    }

   
    Sprite sprite_fondo;
    sprite_fondo.setTexture(texture_fondo);

    
    float escalaX = 800.0f / texture_fondo.getSize().x;
    float escalaY = 600.0f / texture_fondo.getSize().y;
    sprite_fondo.setScale(escalaX, escalaY);

   
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

       
        window.clear();
        window.draw(sprite_fondo);
        window.display();
    }

    return 0;
}
