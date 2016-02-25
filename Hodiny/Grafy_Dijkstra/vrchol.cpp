#include "vrchol.h"
#include <QPainter>

Vrchol::Vrchol()
{
    id = 0;
    barva = "bila";
    prumer = 10;
    this->setPos(0,0);
    hodnota = INT_MAX;
}

Vrchol::Vrchol(int id, int x, int y)
{
    this->id = id;   
    barva = "bila";
    prumer = 10;
    setPos(x,y);//kde v scene se vykresli nas bod
    hodnota = INT_MAX;
}

QRectF Vrchol::boundingRect() const  //ctverec kolem tecky
{
    return QRectF(-prumer/2,-prumer/2,prumer, prumer);
    //-prumer/2 proto, lebo chceme, aby x,y z pos() byl stred nasej tecky
}

void Vrchol::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->setPen(Qt::black);
    painter->drawEllipse(boundingRect());
}

int Vrchol::GetHodnota() const
{
    return hodnota;
}

void Vrchol::SetHodnota(int value)
{
    hodnota = value;
}

int Vrchol::GetId()
{
    return id;
}

void Vrchol::SetId(int value)
{
    id = value;
}

QPoint Vrchol::GetQPoint()
{
    return QPoint(this->x(),this->y());
}

QString Vrchol::GetBarva()
{
    return barva;
}

void Vrchol::SetBarva(QString barva)
{
    this->barva = barva;
}



