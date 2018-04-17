#pragma once
#include "Spaceship.h"
class Enemy:public Spaceship
{
	int speed;
public:
	Enemy(ALLEGRO_BITMAP* Image);
	void Update();
	~Enemy();
	void LoseHP(int hit);
};