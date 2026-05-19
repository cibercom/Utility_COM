#include <SFML/Graphics.hpp>
#include <windows.h> // Optional: used here for Windows-specific features

int main() {
    // 1. Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Hello World");

    // 2. Load a font (required for displaying text)
    sf::Font font;
    // Note: You must have a valid .ttf file in your project folder
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }

    // 3. Create a text object
    sf::Text text("Hello SFML!", font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition(250.f, 250.f);

    // 4. Start the game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit event
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 5. Rendering
        window.clear();          // Clear with black
        window.draw(text);       // Draw the text
        window.display();        // Update the window
    }

    return 0;
}