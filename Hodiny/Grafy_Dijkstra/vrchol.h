#ifndef BOD_H
#define BOD_H

#include <QPoint>
#include <QString>
#include <QGraphicsItem>

class Vrchol : public QGraphicsItem
{
public:
    Vrchol();
    Vrchol(int id, int x, int y);


    int GetId();
    void SetId(int value);
    QString GetBarva();
    void SetBarva(QString barva);
    QPoint GetQPoint();
    int GetHodnota() const;
    void SetHodnota(int value);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int id;
    int hodnota;
    QString barva;
    int prumer;
};

#endif // BOD_H
