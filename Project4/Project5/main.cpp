#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

int main() {

    Texture texture;
    vector<Sprite> sprites;

    string ruta = "plataforma.jpg";
    texture.loadFromFile(ruta);

    float width = texture.getSize().x;
    float height = texture.getSize().y;
    float espacio = 20.0f;  

   
    for (int i = 0; i < 7; i++) {
        Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.15f, 0.2f * (i + 1));
        sprite.setPosition(i * (width * 0.15f + espacio) + 20, 600 - (i + 1) * width * 0.15f);
        sprites.push_back(sprite);
    }

    
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.2f * 7, 0.15f);
    sprite.setPosition(7 * (width * 0.15f + espacio) + 20, height * 0.2f * 6.5f);
    sprites.push_back(sprite);

   
    RenderWindow App(VideoMode(800, 600, 32), "Plataformas");

    
    while (App.isOpen()) {
        App.clear();

        
        for (auto& sprite : sprites) {
            App.draw(sprite);
        }

        App.display();
    }

    return 0;
}
