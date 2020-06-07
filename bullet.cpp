#include<enemy.h>
#include<bullet.h>
bullet::bullet():p(position(0,0))
{
    damage=100;
    speed=200;
}
bullet::~bullet()
{
    ;
}
void bullet::offend(enemy a)
{
    a.life=a.life-100;
}
