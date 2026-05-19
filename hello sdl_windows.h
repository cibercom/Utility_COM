#include <windows.h> // Include Windows-specific headers if needed
#include <SDL.h>     // Core SDL library
#include <stdio.h>

int main(int argc, char* argv[]) {
    // 1. Initialize SDL Video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // 2. Create the window
    SDL_Window* window = SDL_CreateWindow(
        "Hello SDL World",         // Window title
        SDL_WINDOWPOS_CENTERED,     // X position
        SDL_WINDOWPOS_CENTERED,     // Y position
        640, 480,                   // Width, Height
        SDL_WINDOW_SHOWN            // Flags
    );

    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // 3. Simple Event Loop
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // 4. Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}