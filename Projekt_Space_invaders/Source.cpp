#include "Includes.h"
#include "Game.h"
#include "Spaceship.h"
#include"Bullet.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

using namespace std;

enum KEYS { UPP, DOWNN, LEFTT, RIGHTT,SPACE };
bool keys[5] {false,false,false,false,false};
int main()
{
	//ALLEGRO INITIALIZATIONS
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_native_dialog_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	//---------------------------
	srand(time(NULL));
	Game New_Game;
	New_Game.StartGame();
	Spaceship Ship(New_Game.spaceimage);
	bool redraw = true;
	vector <Bullet*> vec_bull;
	vector <Enemy*> vec_enemy;
	while (New_Game.ev.keyboard.keycode!=ALLEGRO_KEY_ESCAPE)
	{
		al_wait_for_event(New_Game.event_queue, &New_Game.ev);
		if (New_Game.ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if (keys[UPP] && !keys[DOWNN])
				Ship.Update();
			if (keys[DOWNN] && !keys[UP])
				Ship.Update();
			if (keys[LEFTT] && !keys[RIGHTT])
				Ship.Update();
			if (keys[RIGHTT] && !keys[LEFTT] )
				Ship.Update();
			if (New_Game.ev.timer.source == New_Game.timer2)
			{
					Bullet* b = new Bullet(Ship.GetX(), Ship.GetY());
					vec_bull.push_back(b);
					Enemy *en = new Enemy(New_Game.enemyimage);
					vec_enemy.push_back(en);
			}
			for (int i = 0; i < vec_bull.size(); i++)
			{
				vec_bull[i]->Update();
				if (vec_bull[i]->checkalive() == false)
					vec_bull.erase(vec_bull.begin() + i);
			}
			for (int i = 0; i < vec_enemy.size(); i++)
			{
				vec_enemy[i]->Update();
				vec_enemy[i]->Render();
			}
			for (int j = 0; j < vec_enemy.size(); j++)
			{
				for (int i = 0; i < vec_bull.size(); i++)
				{
					if ((vec_bull[i]->GetX() >= vec_enemy[j]->GetX() && vec_bull[i]->GetX() <= vec_enemy[j]->GetX() + vec_enemy[j]->GetSize()) && (vec_bull[i]->GetY() >= vec_enemy[i]->GetY() && vec_bull[i]->GetY() <= vec_enemy[i]->GetY() + vec_enemy[i]->GetSize()))
					{
						vec_enemy[j]->LoseHP(1);
						if (vec_enemy[j]->GetHP() < 1)
						{
							vec_enemy.erase(vec_enemy.begin() + j);
							j++;
						}
					}
				}
			}
		}
			else if (New_Game.ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					switch (New_Game.ev.keyboard.keycode)
					{
					case ALLEGRO_KEY_LEFT:
						keys[LEFTT] = true;
						if (keys[UP])
							Ship.SetDirection(UP_LEFT);
						else if (keys[DOWN])
							Ship.SetDirection(DOWN_LEFT);
						else
						Ship.SetDirection(LEFT);
						break;
					case ALLEGRO_KEY_RIGHT:
						keys[RIGHTT] = true;
						if (keys[UP])
							Ship.SetDirection(UP_RIGHT);
						else if (keys[DOWN])
							Ship.SetDirection(DOWN_RIGHT);
						else 
						Ship.SetDirection(RIGHT);
						break;
					case ALLEGRO_KEY_UP:
						keys[UPP] = true;
						if (keys[LEFT])
							Ship.SetDirection(UP_LEFT);
						else if (keys[RIGHT])
							Ship.SetDirection(UP_RIGHT);
						else 
						Ship.SetDirection(UP);
						break;
					case ALLEGRO_KEY_DOWN:
						keys[DOWNN] = true;
						if (keys[LEFT])
							Ship.SetDirection(DOWN_LEFT);
						else if (keys[RIGHT])
							Ship.SetDirection(DOWN_RIGHT);
						else
						Ship.SetDirection(DOWN);
						break;
					case ALLEGRO_KEY_SPACE:
					//	keys[SPACE] = true;
					//	Bullet* b = new Bullet(Ship.GetX(), Ship.GetY());
					//	vec_bull.push_back(b);
						break;
					}
				}
		else if(New_Game.ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (New_Game.ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				keys[LEFTT] = false;
				if (Ship.GetDirection() == UP_LEFT)
					Ship.SetDirection(UP);
				if (Ship.GetDirection() == DOWN_LEFT)
					Ship.SetDirection(DOWN);
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHTT] = false;
				if (Ship.GetDirection() == UP_RIGHT)
					Ship.SetDirection(UP);
				if (Ship.GetDirection() == DOWN_RIGHT)
					Ship.SetDirection(DOWN);
				break;
			case ALLEGRO_KEY_UP:
				keys[UPP] = false;
				if (Ship.GetDirection() == UP_LEFT)
					Ship.SetDirection(LEFT);
				if (Ship.GetDirection() == UP_RIGHT)
					Ship.SetDirection(RIGHT);
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWNN] = false;
				if (Ship.GetDirection() == DOWN_LEFT)
					Ship.SetDirection(LEFT);
				if (Ship.GetDirection() == DOWN_RIGHT)
					Ship.SetDirection(RIGHT);
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}
			if (redraw && al_is_event_queue_empty(New_Game.event_queue))
			{
					redraw = false;
					Ship.Render();
					for (int i = 0; i < vec_bull.size(); i++)
					{
						vec_bull[i]->Render();
					}

					//for (int i = 0; i < Bullet::bul_vec.size(); i++)
					//{
						//Bullet::bul_vec[i]->Render();
					//}
					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
					
			}
	}
	return 0;
}