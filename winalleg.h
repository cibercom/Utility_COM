#include <allegro.h>
#include <winalleg.h> // Incluye windows.h de forma segura para Allegro

int main() {
    // Inicialización clásica de Allegro
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    
    // Configuración de pantalla
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Error al iniciar el modo gráfico\n%s\n", allegro_error);
        return 1;
    }

    // Ejemplo de uso de la API de Windows (<windows.h>)
    MessageBox(
        win_get_window(),
        "Bienvenido a tu juego con Allegro y Windows API",
        "Ventana de Mensaje Win32",
        MB_OK | MB_ICONINFORMATION
    );

    // Bucle principal
    while (!key[KEY_ESC]) {
        // Lógica de dibujo o movimiento
    }

    allegro_exit();
    return 0;
}
END_OF_MAIN() // Necesario para la compatibilidad con Windows en Allegro