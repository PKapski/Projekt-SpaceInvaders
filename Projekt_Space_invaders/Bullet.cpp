#include "Bullet.h"
Bullet::Bullet(int _x, int _y)
{
	x = _x;
	y = _y;
	//bul_vec.push_back(this);
	direction = UP;
}
void Bullet::Render()
{
	al_draw_filled_rectangle(x+35, y, x+45 , y+20 , al_map_rgb(255, 0, 0));
}
void Bullet::Update()
{	
	if (direction == UP)
	{
		y -= 5 * vel;
		if (y < 0)
			alive = false;
	}
}