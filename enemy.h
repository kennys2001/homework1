#ifndef ENEMY_H
#define ENEMY_H
#include<position.h>
class enemy
{
public:
    enemy();
    ~enemy();
    int life;

private:

    int speed;
     position p;
};

#endif // ENEMY_H
