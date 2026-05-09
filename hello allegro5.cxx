#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *font = NULL;

    // 1. Inicializar Allegro
    if (!al_init()) {
        printf("Error al inicializar Allegro\n");
        return -1;
    }

    // 2. Inicializar el addon de fuentes
    al_init_font_addon();
    al_init_ttf_addon();

    // 3. Crear la ventana
    display = al_create_display(640, 480);
    if (!display) {
        printf("Error al crear la pantalla\n");
        return -1;
    }

    // 4. Cargar una fuente (ttf) o usar la fuente incorporada
    // Nota: Necesitas un archivo .ttf en la misma carpeta o usar la builtin
    font = al_create_builtin_font();

    // 5. Ciclo de dibujo
    al_clear_to_color(al_map_rgb(0, 0, 0)); // Fondo negro
    
    // Dibujar texto: fuente, color, x, y, flags, texto
    al_draw_text(font, al_map_rgb(255, 255, 255), 640/2, 480/2, ALLEGRO_ALIGN_CENTRE, "Hola desde Cxxdroid!");
    
    al_flip_display(); // Mostrar en pantalla

    // 6. Esperar unos segundos antes de cerrar
    al_rest(5.0);

    // 7. Limpieza
    al_destroy_font(font);
    al_destroy_display(display);

    return 0;
}