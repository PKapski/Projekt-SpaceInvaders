#include "Spaceship.h"
Spaceship::Spaceship(ALLEGRO_BITMAP* Image)
{
	image = Image;
	size = 80;
	x = 380;
	y = 500;
	health = 1;
}
Spaceship::Spaceship()
{

}
void Spaceship::Render()
{
	al_draw_bitmap(image, x, y, NULL);
}
void Spaceship::Update()
{
	if (direction == UP)
	{
		y -= 5 * vel;
		if (y < 0)
			y = 0;
	}
	if (direction == DOWN)
	{
		y += 5 * vel;
		if (y > ScreenHeight - size)
			y = ScreenHeight - size;
	}
	if (direction == LEFT)
	{
		x -= 5 * vel;
		if (x <0)
			x = 0;
	}
	if (direction == RIGHT)
	{
		x += 5 * vel;
		if (x > ScreenWidth - size)
			x = ScreenWidth - size;
	}
	if (direction == UP_LEFT)
	{
		y -= 2.5 * vel;
		if (y < 0)
			y = 0;
		x -= 2.5 * vel;
		if (x <0)
			x = 0;
	}
	if (direction == UP_RIGHT)
	{
		y -= 2.5 * vel;
		if (y < 0)
			y = 0;
		x += 2.5 * vel;
		if (x > ScreenWidth - size)
			x = ScreenWidth - size;
	}
	if (direction == DOWN_LEFT)
	{
		y += 2.5 * vel;
		if (y > ScreenHeight - size)
			y = ScreenHeight - size;
		x -= 2.5 * vel;
		if (x <0)
			x = 0;
	}
	if (direction == DOWN_RIGHT)
	{
		x += 2.5 * vel;
		if (x > ScreenWidth - size)
			x = ScreenWidth - size;
		y += 2.5 * vel;
		if (y > ScreenHeight - size)
			y = ScreenHeight - size;
	}
}