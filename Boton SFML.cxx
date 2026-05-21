#include <SFML/Graphics.hpp>
#include <iostream>

int main( int argc, char *argv [] ) {
    // 1. Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Boton en SFML - CxxDroid");
    window.setFramerateLimit(60);

    // 2. Definir la forma del botón
    sf::RectangleShape button(sf::Vector2f(200.0f, 80.0f));
    button.setPosition(300.0f, 260.0f);
    button.setFillColor(sf::Color::Blue);
    
    // Para cambiar de color al pasar el ratón o hacer clic
    sf::Color idleColor = sf::Color::Blue;
    sf::Color hoverColor = sf::Color::Cyan;
    sf::Color activeColor = sf::Color::Green;

    // 3. Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // 4. Detectar clics
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    
                    // Comprobar si el clic está dentro de los límites del botón
                    if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        button.setFillColor(activeColor);
                        std::cout << "¡Botón clickeado!" << std::endl;
                    }
                }
            }
            
            // Restablecer color al soltar el clic
            if (event.type == sf::Event::MouseButtonReleased) {
                button.setFillColor(idleColor);
            }
        }

        // 5. Detectar si el cursor está sobre el botón (Hover)
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                button.setFillColor(activeColor);
            } else {
                button.setFillColor(hoverColor);
            }
        } else {
            button.setFillColor(idleColor);
        }

        // 6. Renderizar en pantalla
        window.clear(sf::Color(50, 50, 50)); // Fondo gris oscuro
        window.draw(button);
        window.display();
    }

    return 0;
}