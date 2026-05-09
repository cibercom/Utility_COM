#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    // 1. Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo Texto SFML en Cxxdroid");

    // 2. Cargar una fuente
    // IMPORTANTE: Debes tener un archivo .ttf en la misma carpeta o poner la ruta correcta
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // Manejo de error si no se encuentra la fuente
        std::cout << "Error: No se pudo cargar la fuente" << std::endl;
        // En Android, a veces la ruta es "/system/fonts/DroidSans.ttf"
        if (!font.loadFromFile("/system/fonts/DroidSans.ttf")) {
            return -1;
        }
    }

    // 3. Crear el objeto de texto
    sf::Text text;
    text.setFont(font); // Seleccionar la fuente
    text.setString("Hola Cxxdroid!"); // El texto a mostrar
    text.setCharacterSize(50); // Tamaño en pixeles
    text.setFillColor(sf::Color::White); // Color
    text.setStyle(sf::Text::Bold | sf::Text::Underlined); // Estilo
    
    // Centrar el texto
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(800/2.0f, 600/2.0f));

    // 4. Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black); // Limpiar con color negro
        
        // 5. Dibujar el texto
        window.draw(text);
        
        window.display(); // Mostrar en pantalla
    }

    return 0;
}