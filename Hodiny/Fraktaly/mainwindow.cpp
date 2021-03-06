#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->view->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::VykresliTrojuhelnik(int n, QPoint a, QPoint b, QPoint c)
{
    if(n>0)
    {
        scene.addLine(a.x(), a.y(), b.x(), b.y());
        scene.addLine(b.x(), b.y(), c.x(), c.y());
        scene.addLine(c.x(), c.y(), a.x(), a.y());
        VykresliTrojuhelnik(n-1, a, (a+b)/2, (a+c)/2);
        VykresliTrojuhelnik(n-1, (a+b)/2, b, (b+c)/2);
        VykresliTrojuhelnik(n-1, (b+c)/2, (a+c)/2, c);
    }
}

void MainWindow::VykresliKriz(int n, QPoint a, int velikost)
{
    if(n>0)
    {
        scene.addLine(a.x()-velikost/2,a.y(), a.x()+velikost/2, a.y());
        scene.addLine(a.x(),a.y()-velikost/2, a.x(), a.y()+velikost/2);
        VykresliKriz(n-1, QPoint(a.x()-velikost/2, a.y()), velikost/2);
        VykresliKriz(n-1, QPoint(a.x()+velikost/2, a.y()), velikost/2);
        VykresliKriz(n-1, QPoint(a.x(), a.y()-velikost/2), velikost/2);
        VykresliKriz(n-1, QPoint(a.x(), a.y()+velikost/2), velikost/2);
    }
}

void MainWindow::VykresliSpiralu(int n, QPoint a, QPoint b)
{
    if(n>0)
    {
        scene.addLine(a.x(), a.y(), b.x(), b.y());
        if(a.y() - b.y() < 0)
            VykresliSpiralu(n-1, b, QPoint(b.x() - (b.y() - a.y())*0.9, b.y()));
        else if(a.x() - b.x() > 0)
            VykresliSpiralu(n-1, b, QPoint(b.x(), b.y() - (a.x() - b.x())*0.9));
        else if(a.y() - b.y() > 0)
            VykresliSpiralu(n-1, b, QPoint(b.x() + (a.y() - b.y())*0.9, b.y()));
        else if(a.x() - b.x() < 0)
            VykresliSpiralu(n-1, b, QPoint(b.x(), b.y() + (b.x() - a.x())*0.9));
    }
}

void MainWindow::VykresliExcKruhy(int n, QPoint a, int velikost)
{
    if(n>0)
    {
        int polVel = velikost/2;
        scene.addEllipse(a.x()-polVel, a.y()-polVel, velikost, velikost);
        if(n>1)
        {
            scene.addLine(a.x(),a.y()-polVel, a.x()+polVel, a.y()-(velikost*0.8)/2);
            scene.addLine(a.x(),a.y()+polVel+1, a.x()+polVel, a.y()+(velikost*0.8)/2+1);
        }
        VykresliExcKruhy(n-1,QPoint(a.x()+polVel, a.y()), velikost*0.8);
    }
}

void MainWindow::VykresliStrom(int n, QPoint a, QPoint b, QPoint c, QPoint d)
{
    if(n>0)
    {
        QPolygon poly;
        poly.append(a);
        poly.append(b);
        poly.append(c);
        poly.append(d);
        scene.addPolygon(poly, QPen(Qt::green), QBrush(QColor(102,51,0)));
        QPoint middle = (d+b)/2 + b - c;
        VykresliStrom(n-1, middle + middle - a, b + middle - a, b, middle);
        VykresliStrom(n-1, middle + middle - b, a + middle - b, a, middle);
    }
}

void MainWindow::VykresliPicoid(int n, QPoint a, QPoint b, QPoint c, QPoint d)
{
    if(n>0)
    {
        QPolygon poly;
        poly.append(a);
        poly.append(b);
        poly.append(c);
        poly.append(d);
        scene.addPolygon(poly);
        VykresliPicoid(n-1, (a+b)/2, (b+c)/2, (c+d)/2, (d+a)/2);
    }
}

void MainWindow::VykresliCtverec(int n, QRect a)
{
    if(n>0)
    {
        scene.addRect(a.x(), a.y(), a.width(), a.height());
        VykresliCtverec(n-1, QRect(a.x()+a.width()/4, a.y(), a.width()/2, a.height()/2));
        VykresliCtverec(n-1, QRect(a.x(), a.y()+a.height()/4, a.width()/2, a.height()/2));
        VykresliCtverec(n-1, QRect(a.x()+a.width()/4, a.y()+a.height()/2, a.width()/2, a.height()/2));
        VykresliCtverec(n-1, QRect(a.x()+a.width()/2, a.y()+a.height()/4, a.width()/2, a.height()/2));
    }
}

void MainWindow::VykresliCtverec2(int n, int x, int y, int side)
{
    if(n>0)
    {
        QRadialGradient gradient(x+side/2, y+side/2, side/6);
        if(n == 4)
            gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
        if(n == 3)
            gradient.setColorAt(0, QColor::fromRgbF(0, 0.75, 0.5, 1));
        if(n == 2)
            gradient.setColorAt(0, QColor::fromRgbF(0, 0.5, 0.75, 1));
        if(n == 1)
            gradient.setColorAt(0, QColor::fromRgbF(0, 0, 1, 1));

        gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
        double sub = side/3;
        scene.addRect(x + sub, y + sub, sub - 1, sub - 1, QPen(Qt::transparent), gradient);
        if (sub >= 3) {
            VykresliCtverec2(n-1, x, y, sub);
            VykresliCtverec2(n-1, x + sub, y, sub);
            VykresliCtverec2(n-1, x + 2 * sub, y, sub);
            VykresliCtverec2(n-1, x, y + sub, sub);
            VykresliCtverec2(n-1, x + 2 * sub, y + sub, sub);
            VykresliCtverec2(n-1, x, y + 2 * sub, sub);
            VykresliCtverec2(n-1, x + sub, y + 2 * sub, sub);
            VykresliCtverec2(n-1, x + 2 * sub, y + 2 * sub, sub);
        }
    }
}

void MainWindow::VykresliStrom2(int n, QPointF startPoint, double lenght, double angle)
{
    if(n>0)
    {
        QPoint endPoint = QPoint(startPoint.x(), startPoint.y()-lenght);
        QLineF line = QLineF(startPoint, endPoint);
        line.setAngle(angle);
        scene.addLine(line);
        VykresliStrom2(n-1, line.p2(), (lenght/3)*2, line.angle() - (90 + ui->horizontalSlider->value()));
        VykresliStrom2(n-1, line.p2(), (lenght/3)*2, line.angle() + 90 + ui->horizontalSlider->value());
    }

}

void MainWindow::VykresliSachovnici(int vel, int num)
{
    for(int i = 0; i < num; ++i)
    {
        for(int j = 0; j < num; ++j)
        {
            QBrush brush = QBrush(Qt::white);
            if((i+j)%2==0)
                brush = QBrush(Qt::black);
            scene.addRect(QRect(vel*i,vel*j,vel,vel),QPen(Qt::black),brush);
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliTrojuhelnik(ui->verticalSlider->value(), QPoint(0,0), QPoint(200,0), QPoint(100,-150));
}

void MainWindow::on_pushButton_2_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliKriz(ui->verticalSlider->value(), QPoint(0, 0), 150);
}


void MainWindow::on_pushButton_3_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliSpiralu(ui->verticalSlider->value(), QPoint(-50, -50), QPoint(50, -50));
}

void MainWindow::on_pushButton_4_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));\
    VykresliExcKruhy(ui->verticalSlider->value(), QPoint(0,0), 100);
}

void MainWindow::on_pushButton_5_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliStrom(ui->verticalSlider->value(), QPoint(10,0), QPoint(40,0), QPoint(40,30), QPoint(10, 30));
}

void MainWindow::on_pushButton_6_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliPicoid(ui->verticalSlider->value(), QPoint(0,0),QPoint(50,0),QPoint(50,50),QPoint(0,50));
}

void MainWindow::on_pushButton_7_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliCtverec(ui->verticalSlider->value(), QRect(0, 0, 200, 200));
}
void MainWindow::on_pushButton_8_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::black));
    QRect a = QRect(0,0,200,200);
//    scene.addRect(a, QPen(Qt::black), QBrush(Qt::black));
    VykresliCtverec2(ui->verticalSlider->value(), 0, 0, 400);
}
void MainWindow::on_pushButton_9_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliStrom2(ui->verticalSlider->value(), QPointF(200,200), 75, 90);
}
void MainWindow::on_pushButton_10_clicked()
{
    scene.clear();
    scene.setBackgroundBrush(QBrush(Qt::white));
    VykresliSachovnici(25, 8);
}
