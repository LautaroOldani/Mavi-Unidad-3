#include <string>
#include <format>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
using namespace std;
int main() {

    string ruta = "plataforma.jpg";

    Texture texture;
    texture.loadFromFile(ruta);

    float width = texture.getSize().x;
    float height = texture.getSize().y;

    Sprite sprite;
    sprite.setTexture(texture);

    sprite.setPosition(800 - (400 - (width / 2)), 600 - (300 - (height / 2)));

    RenderWindow App(VideoMode(800, 600, 32), "Rotación");

    while (App.isOpen()) {
        App.clear();
        sprite.rotate(1.0f);
        App.draw(sprite);
        App.display();
    }

    return 0;
}
