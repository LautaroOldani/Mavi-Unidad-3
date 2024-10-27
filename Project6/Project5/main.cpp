#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    string ruta_negro = "chessb.png";
    string ruta_azul = "cuad_blue.png";
    string ruta_rojo = "cuad_red.png";
    string ruta_amarillo = "cuad_yellow.png";

    // Cargo archivo
    Texture t_negro, t_azul, t_rojo, t_amarillo;

    if (!t_negro.loadFromFile(ruta_negro)) {
        cout << "Error al cargar la textura negra" << endl;
        return 1; 
    }
    if (!t_azul.loadFromFile(ruta_azul)) {
        cout << "Error al cargar la textura azul" << endl;
        return 1;
    }
    if (!t_rojo.loadFromFile(ruta_rojo)) {
        cout << "Error al cargar la textura roja" << endl;
        return 1;
    }
    if (!t_amarillo.loadFromFile(ruta_amarillo)) {
        cout << "Error al cargar la textura amarilla" << endl;
        return 1;
    }

  
    const float tam_cuadro = 400.f;

    Sprite s_negro, s_azul, s_rojo, s_amarillo;
    s_negro.setTexture(t_negro);
    s_azul.setTexture(t_azul);
    s_rojo.setTexture(t_rojo);
    s_amarillo.setTexture(t_amarillo);

  
    s_negro.setScale(tam_cuadro / t_negro.getSize().x, tam_cuadro / t_negro.getSize().y);
    s_azul.setScale(tam_cuadro / t_azul.getSize().x, tam_cuadro / t_azul.getSize().y);
    s_rojo.setScale(tam_cuadro / t_rojo.getSize().x, tam_cuadro / t_rojo.getSize().y);
    s_amarillo.setScale(tam_cuadro / t_amarillo.getSize().x, tam_cuadro / t_amarillo.getSize().y);

   
    s_rojo.setPosition(0, 0);        
    s_amarillo.setPosition(tam_cuadro, 0); 
    s_azul.setPosition(0, tam_cuadro);   
    s_negro.setPosition(tam_cuadro, tam_cuadro); 

    RenderWindow App(VideoMode(800, 800, 32), "Cuadrados del mismo tamaño");

    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }

        App.clear();
        App.draw(s_rojo);
        App.draw(s_amarillo);
        App.draw(s_azul);
        App.draw(s_negro);
        App.display();
    }

    return 0;
}
