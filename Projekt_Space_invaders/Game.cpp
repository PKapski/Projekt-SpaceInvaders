#include "Game.h"
#include <iostream>
using namespace std;

	Game::Game()
	{
		event_queue = al_create_event_queue();
		event_queue2 = al_create_event_queue();
		al_register_event_source(event_queue, al_get_keyboard_event_source());
		display = al_create_display(ScreenWidth,ScreenHeight);
		if (!display) {
			al_show_native_message_box(display, "Error", "Display Settings", "Couldn't create a display.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			exit(-1);
		}
		spaceimage = al_load_bitmap("alienblaster3.bmp");
		enemyimage = al_load_bitmap("alienblaster2.bmp");
		if (!spaceimage || !enemyimage) {
			al_show_native_message_box(display, "Error", "Bitmaps Error", "Bitmaps not loaded correctly.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			exit(-1);
		}
		timer = al_create_timer(1.0 / FPS);
		timer2 = al_create_timer(1.0 / 6.0);
		if (!timer) {
			fprintf(stderr, "failed to create timer!\n");
			exit(-1);
		}

		al_register_event_source(event_queue, al_get_timer_event_source(timer));
		al_register_event_source(event_queue, al_get_timer_event_source(timer2));
	}
	void Game::StartGame()
	{
		al_set_app_name("Space Invaders");
		al_set_new_display_flags(ALLEGRO_WINDOWED);
		al_set_window_title(display, "SpaceInvaders");
		al_flip_display();
		al_convert_mask_to_alpha(spaceimage, al_map_rgb(255, 0, 255));
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_start_timer(timer);
		al_start_timer(timer2);
		cin;
	}
