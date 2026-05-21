#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // 1. Inicializar Allegro
    if (!al_init()) return -1;
    al_init_primitives_addon();
    al_install_mouse();

    // 2. Crear display y cola de eventos
    ALLEGRO_DISPLAY *display = al_create_display(600, 400);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30); // 30 FPS

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    bool running = true;
    
    // 3. Coordenadas del botón
    int btn_x1 = 200, btn_y1 = 150;
    int btn_x2 = 400, btn_y2 = 250;

    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        } 
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            // Detectar clic (o toque) dentro del área del botón
            if (event.mouse.x >= btn_x1 && event.mouse.x <= btn_x2 &&
                event.mouse.y >= btn_y1 && event.mouse.y <= btn_y2) {
                printf("Hello\n");
            }
        }
        else if (event.type == ALLEGRO_EVENT_TIMER) {
            // Dibujar fondo
            al_clear_to_color(al_map_rgb(50, 50, 50));

            // Dibujar botón (rectángulo rojo)
            al_draw_filled_rectangle(btn_x1, btn_y1, btn_x2, btn_y2, al_map_rgb(200, 50, 50));

            al_flip_display();
        }
    }

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    return 0;
}