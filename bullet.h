#ifndef BULLET_H
#define BULLET_H
#include<enemy.h>
#include<position.h>
class bullet
{
public:
    bullet();
    ~bullet();
    void offend(enemy a);

private:
    int damage;
    int speed;
    position p;
};

#endif // BULLET_H
