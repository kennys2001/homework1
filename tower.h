#ifndef TOWER_H
#define TOWER_H
#include<position.h>
class tower
{
public:
    tower();
    ~tower();
    void attack();
    void change_state();

    bool state;
private:

    double range;
    int level;
    int CD;
     position p;
};
#endif // TOWER_H
