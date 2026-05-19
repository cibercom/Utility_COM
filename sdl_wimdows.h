#include <windows.h>
#include <SDL2/SDL.h>
#include <stdio.h>

// El punto de entrada nativo para las aplicaciones de Windows
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Informa a SDL que nosotros mismos gestionamos el punto de entrada WinMain
    SDL_SetMainReady();

    // Inicializar el subsistema de Video de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Crear la ventana
    SDL_Window* ventana = SDL_CreateWindow(
        "Ventana SDL y Windows API",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (ventana == NULL) {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Mantener la ventana abierta durante 5 segundos (5000 ms)
    SDL_Delay(5000);

    // Limpiar y destruir la ventana
    SDL_DestroyWindow(ventana);
    SDL_Quit();

    return 0;
}