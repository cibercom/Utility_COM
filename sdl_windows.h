#include <windows.h>
#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Inicializar la API de Windows
    MessageBox(NULL, "Ventana creada con exito", "Mensaje de Win32", MB_OK);

    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Crear la ventana SDL
    SDL_Window* window = SDL_CreateWindow("Ventana SDL", 
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                          800, 600, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Esperar 3 segundos
    SDL_Delay(3000);

    // Limpiar y salir
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}