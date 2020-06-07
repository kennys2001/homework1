#ifndef POSITION_H
#define POSITION_H
class position
{
public:
    position(int a,int b);
    position();
    ~position();
    double get_positionX();
    double get_positionY();
private:
    double x;
    double y;
};

#endif // POSITION_H
