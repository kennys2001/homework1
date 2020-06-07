#include "widget.h"
#include "ui_widget.h"
#include<math.h>
#include<bullet.h>
#include<tower.h>
#include <QPainter>
#include <QTimer>
#include<QTime>


int t=0;
int v=2;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tower.append(position(500,300));
    enemy.append(position(150,300));
    enemy.append(position(100,300));
    QTimer *time=new QTimer(this);
    time->start(50);
    connect(time,&QTimer::timeout,[=]()
    {

        if(enemy.size()>=0)
        {
            for(auto i=0;i<enemy.size();i++)
            {
                enemy[i]=position(enemy[i].get_positionX()+2,enemy[i].get_positionY());
            }
        }
        for(auto i=0;i<enemy.size();i++)
        {
            if(fabs(enemy[i].get_positionX()-tower[0].get_positionX())<300)
            {

                if(t%20==0)
                {
                    bullet.append(position(tower[0]));
                    t=t-20;
                }
                //Tower[0].change_state();
            }
        }
        for(auto i=0;i<bullet.size();i++)
        {
            bullet[i]=position(bullet[i].get_positionX()-4,bullet[i].get_positionY());
        }
        for(auto i=0;i<bullet.size();i++)
        {
            int p=v;
            for(auto j=p-v;j<enemy.size();j++)
            {
                if(bullet[i].get_positionX()==enemy[j].get_positionX()&&bullet[i].get_positionY()==enemy[j].get_positionY())
                {
                    Bullet[i].~bullet();
                    bullet[i]=position(-1,-100);
                    Enemy[j].life=Enemy[j].life-100;
                    if(Enemy[j].life<=0)
                    {
                        Enemy[j].~enemy();
                        enemy[j]=position(-1,-100);
                        v--;
                    }
                }
            }
        }


        update();
        if(v>0)
        t++;
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawPixmap(tower[0].get_positionX(),tower[0].get_positionY(),20,20,QPixmap(":/resource/tower.png"));
   for(int i=0;i<enemy.size();i++)
   {
       if(enemy[i].get_positionX()!=0&&enemy[i].get_positionY()!=0)
        painter.drawPixmap(enemy[i].get_positionX(),enemy[i].get_positionY(),10,10,QPixmap(":/resource/enemy.png"));
   }
   for(int i=0;i<bullet.size();i++)
   {
       if(bullet[i].get_positionX()!=0&&bullet[i].get_positionX()!=0)
           painter.drawPixmap(bullet[i].get_positionX(),bullet[i].get_positionY(),10,10,QPixmap(":/resource/bullet.png"));
   }

}
