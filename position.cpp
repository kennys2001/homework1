#include<position.h>
position::position()
{
    x=0;
    y=0;
}
position::position(int a,int b)
{
    x=a;
    y=b;
}
position::~position()
{
    ;
}
double position::get_positionX()
{
    return x;
}
double position::get_positionY()
{
    return y;
}
