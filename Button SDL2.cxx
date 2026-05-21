#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* args[]) {
    // 1. Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Crear ventana y renderizador
    SDL_Window* window = SDL_CreateWindow("Boton SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 2. Definir el botón (coordenadas x, y, ancho, alto)
    SDL_Rect botonRect = { 300, 250, 200, 100 };
    bool quit = false;
    bool botonPresionado = false;
    SDL_Event e;

    // Bucle principal
    while (!quit) {
        // Manejo de eventos
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Comprobar si el clic está dentro del rectángulo del botón
                if (x >= botonRect.x && x <= botonRect.x + botonRect.w &&
                    y >= botonRect.y && y <= botonRect.y + botonRect.h) {
                    botonPresionado = !botonPresionado; // Cambia de estado al hacer clic
                    printf("¡Boton presionado!\n");
                }
            }
        }

        // 3. Renderizado
        // Fondo de pantalla (azul)
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);

        // Cambiar color del botón si está presionado (Rojo) o no (Verde)
        if (botonPresionado) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        }
        
        // Dibujar botón
        SDL_RenderFillRect(renderer, &botonRect);

        // Actualizar pantalla
        SDL_RenderPresent(renderer);
    }

    // Liberar recursos y cerrar SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}