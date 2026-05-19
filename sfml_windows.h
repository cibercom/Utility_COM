#include <SFML/Graphics.hpp>

// ¡Regla vital! Incluir windows.h después de las cabeceras de SFML
// de lo contrario, macros de Windows colisionan con tipos de SFML
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Evita que windows.h cargue macros conflictivas
#endif
#include <windows.h>

int main()
{
    // 1. Crear ventana SFML estándar
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "SFML con Windows API");

    // 2. Obtener el Handle de la ventana (HWND) para usar la API de Windows
    HWND hwnd = ventana.getSystemHandle();

    if (hwnd != nullptr)
    {
        // 3. Modificar el título de la ventana usando la API nativa de Windows
        SetWindowText(hwnd, TEXT("¡Título modificado por Windows API!"));
    }

    while (ventana.isOpen())
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }

        ventana.clear(sf::Color::Black);
        // Aquí puedes dibujar elementos con SFML...
        ventana.display();
    }

    return 0;
}