#pragma once
#include "Includes.h"
#include "GameObject.h"
#include "Game.h"
class Spaceship:public GameObject
{
protected:
	int health;
public:
	Spaceship();
	Spaceship(ALLEGRO_BITMAP* Image);
	void Render();
	void Update();
	int GetHP() { return health; }
};