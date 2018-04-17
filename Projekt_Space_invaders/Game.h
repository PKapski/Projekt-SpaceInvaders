#pragma once
#include "Includes.h"
const int ScreenWidth = 800;
const int ScreenHeight = 600;
const float FPS = 60;
class Game
{
public:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *spaceimage,*enemyimage;
	ALLEGRO_EVENT_QUEUE *event_queue,*event_queue2;
	ALLEGRO_EVENT ev,ev2;
	ALLEGRO_TIMER *timer=NULL,*timer2=NULL;

	Game();
	void StartGame();
};