#include<tower.h>
#include<QTimer>
#include<QDebug>
#include<QThread>
#include<QApplication>
tower::tower():p(position(400,400))
{
    level=1;
    CD=1000;
    range=300;
    state=true;
}
tower::~tower()
{
    ;
}
void tower::change_state()
{
    state=false;
    QEventLoop eventloop;
    QTimer::singleShot(500, &eventloop, SLOT(quit()));
    eventloop.exec();

    state=true;

    QApplication::processEvents(QEventLoop::AllEvents,0);



}
