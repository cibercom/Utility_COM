#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // 1. Inicializar Allegro
    if (!al_init()) {
        fprintf(stderr, "Error al inicializar Allegro.\n");
        return -1;
    }

    // 2. Inicializar el teclado y el ratón
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();

    // 3. Crear la pantalla y la cola de eventos
    ALLEGRO_DISPLAY *display = al_create_display(800, 600);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // Coordenadas y tamaño del botón
    float btn_x = 300, btn_y = 250;
    float btn_w = 200, btn_h = 100;
    
    bool running = true;
    bool redraw = true;
    bool boton_presionado = false;

    // 4. Bucle principal del programa
    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        } 
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            // Verificar si el clic ocurrió dentro del botón
            if (ev.mouse.x >= btn_x && ev.mouse.x <= btn_x + btn_w &&
                ev.mouse.y >= btn_y && ev.mouse.y <= btn_y + btn_h) {
                boton_presionado = true;
                printf("¡Botón presionado!\n");
            }
        } 
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            boton_presionado = false;
        }

        if (al_is_event_queue_empty(event_queue)) {
            redraw = true;
        }

        // 5. Dibujar en pantalla
        if (redraw) {
            al_clear_to_color(al_map_rgb(50, 50, 50)); // Fondo gris

            // Cambiar color del botón si está presionado
            if (boton_presionado) {
                al_draw_filled_rectangle(btn_x, btn_y, btn_x + btn_w, btn_y + btn_h, al_map_rgb(0, 200, 0));
            } else {
                al_draw_filled_rectangle(btn_x, btn_y, btn_x + btn_w, btn_y + btn_h, al_map_rgb(0, 100, 0));
            }

            al_flip_display();
            redraw = false;
        }
    }

    // 6. Destruir objetos para liberar memoria
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    return 0;
}