#pragma once
#include "Includes.h"
#include "Game.h"
#include <string>

enum Direction {UP,DOWN,LEFT,RIGHT,UP_RIGHT,UP_LEFT,DOWN_RIGHT,DOWN_LEFT,NONE};

class GameObject
{
protected:
	int x, y, size;
	double vel = 2.0;
	ALLEGRO_BITMAP *image;
	std::string ID;
	Direction direction=NONE;
public:
	int GetX() { return x; }
	void SetX(int x) { GameObject::x = x; }
	int GetY() { return y; }
	void SetY(int y) { GameObject::y = y; }
	int GetDirection() { return direction; }
	void SetDirection(Direction dir) { GameObject::direction = dir; }
	int GetSize() { return size; }
	std::string GetID() { return ID; }
	virtual void Render()=0;
	virtual void Update() = 0;
};