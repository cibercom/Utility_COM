#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_windows.h>
#include <windows.h>

int main() {
    // 1. Inicializar Allegro
    if (!al_init()) {
        return -1;
    }

    // 2. Crear una ventana (Display)
    ALLEGRO_DISPLAY *display = al_create_display(640, 480);
    if (!display) {
        return -1;
    }

    // 3. Obtener el HWND (identificador de ventana nativo de Windows)
    HWND hwnd = al_get_win_window_handle(display);

    // 4. Usar una función de windows.h para mostrar un cuadro de mensaje
    MessageBox(hwnd, TEXT("¡Hola desde Allegro y Windows API!"), TEXT("Ventana de Windows"), MB_OK | MB_ICONINFORMATION);

    // 5. Destruir display y salir
    al_destroy_display(display);

    return 0;
}