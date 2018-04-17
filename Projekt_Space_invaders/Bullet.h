#pragma once
#include "GameObject.h"
#include <vector>
class Bullet :public GameObject
{
	bool alive = true;
public:
	//static std::vector <Bullet*> bul_vec;
	Bullet(int _x, int _y);
	void Render();
	void Update();
	bool checkalive(){ return alive; };
};