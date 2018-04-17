#include "GameObject.h"
#include "Includes.h"


void  GameObject::Render()
{
	al_draw_bitmap(image, GameObject::x, GameObject::y, NULL);
}