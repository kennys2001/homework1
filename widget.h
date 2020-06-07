#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<position.h>
#include<tower.h>
#include<bullet.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QVector<position> enemy;
    QVector<position> tower;
    QVector<position> bullet;
    class tower Tower[2];
    class bullet Bullet[2];
    class enemy Enemy[2];
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
    bool end;
};
#endif // WIDGET_H
