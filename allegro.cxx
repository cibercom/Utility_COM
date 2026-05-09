#include <allegro5/allegro.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    ALLEGRO_DISPLAY *display = NULL;

    // 1. Inicializar Allegro
    if (!al_init()) {
        printf("Error al inicializar Allegro\n");
        return -1;
    }

    // 2. Crear la ventana (display) de 640x480
    display = al_create_display(640, 480);
    if (!display) {
        printf("Error al crear el display\n");
        return -1;
    }

    // 3. Pintar la pantalla de color rojo
    al_clear_to_color(al_map_rgb(255, 0, 0));

    // 4. Actualizar la pantalla
    al_flip_display();

    // 5. Esperar 3 segundos
    al_rest(3.0);

    // 6. Destruir la ventana
    al_destroy_display(display);

    return 0;
}