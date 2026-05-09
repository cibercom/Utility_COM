#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]) {
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo SFML en Cxxdroid");

    // Crear una forma (círculo verde)
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(300.f, 200.f);

    // Crear otra forma (rectángulo azul)
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(340.f, 450.f);

    // Bucle principal de la aplicación
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear(sf::Color::Black);

        // Dibujar las formas
        window.draw(circle);
        window.draw(rectangle);

        // Mostrar lo dibujado
        window.display();
    }

    return 0;
}