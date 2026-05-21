#include <SFML/Graphics.hpp>
#include <iostream>

class Boton {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

    bool isMouseOver(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect bounds = shape.getGlobalBounds();
        return bounds.contains(static_cast<sf::Vector2f>(mousePos));
    }

public:
    Boton(float x, float y, float width, float height, const std::string& btnText, const std::string& fontPath = "") {
        // Posición y tamaño
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Blue);

        // Cargar fuente (usa una fuente predeterminada del sistema o coloca una ruta válida)
        // En Android, puedes usar una ruta relativa a tu proyecto si incluyes el archivo .ttf
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Error al cargar la fuente, usando predeterminada." << std::endl;
        }

        // Configuración del texto
        text.setFont(font);
        text.setString(btnText);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);

        // Centrar el texto en el botón
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                       textBounds.top + textBounds.height / 2.0f);
        text.setPosition(x + width / 2.0f, y + height / 2.0f);
    }

    void update(sf::RenderWindow& window) {
        if (isMouseOver(window)) {
            shape.setFillColor(sf::Color::Cyan); // Color al pasar el ratón (Hover)
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                shape.setFillColor(sf::Color::Green); // Color al hacer clic
            }
        } else {
            shape.setFillColor(sf::Color::Blue); // Color por defecto
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
    
    // Método para saber si fue presionado
    bool isClicked(sf::RenderWindow& window) {
        return isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Botón SFML en Cxxdroid");
    window.setFramerateLimit(60);

    // Crear una instancia del botón
    Boton miBoton(300, 250, 200, 50, "Hazme clic");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                
            // Ejemplo de evento de clic
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (miBoton.isClicked(window)) {
                        std::cout << "¡Botón presionado!" << std::endl;
                    }
                }
            }
        }

        miBoton.update(window);

        window.clear(sf::Color(30, 30, 30));
        miBoton.draw(window);
        window.display();
    }

    return 0;
}