#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main() {
    Texture blanco, negro;
    Sprite sprite_blanco, sprite_negro;

    
    string ruta_blanco = "chessw.png";
    string ruta_negro = "chessb.png";

    
    if (!blanco.loadFromFile(ruta_blanco) || !negro.loadFromFile(ruta_negro)) {
        return -1; 
    }

   
    sprite_blanco.setTexture(blanco);
    sprite_negro.setTexture(negro);

    
    float height = blanco.getSize().y;
    float width = blanco.getSize().x;
    float escalaX = 100 / width;
    float escalaY = 100 / height;
    sprite_blanco.setScale(escalaX, escalaY);
    sprite_negro.setScale(escalaX, escalaY);

   
    RenderWindow App(VideoMode(800, 800, 32), "Tablero de Ajedrez");

   
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }

        App.clear();

       
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                
                if ((row + col) % 2 == 0) {
                    sprite_blanco.setPosition(col * 100, row * 100);
                    App.draw(sprite_blanco);
                }
                else {
                    sprite_negro.setPosition(col * 100, row * 100);
                    App.draw(sprite_negro);
                }
            }
        }

        App.display();
    }

    return 0;
}
