#include "Enemy.h"
#include <time.h>

Enemy::Enemy(ALLEGRO_BITMAP* Image)
{
	size = 40;
	x = (rand() % (600/size))*size;
	y = 0;
	image = Image;
}
Enemy::~Enemy()
{
	delete this;
}
void Enemy::Update()
{
	y += 1.5 * vel;
	if (y > ScreenHeight - size)
		this->~Enemy();
}
void Enemy::LoseHP(int hit)
{
	health -= hit;
}