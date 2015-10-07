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




void MainWindow::on_pushButton_clicked()
{
    scene.clear();
    VykresliTrojuhelnik(ui->verticalSlider->value(), QPoint(0,0), QPoint(200,0), QPoint(100,-150));
}

void MainWindow::on_pushButton_2_clicked()
{
    scene.clear();
    VykresliKriz(ui->verticalSlider->value(), QPoint(0, 0), 150);
}

void MainWindow::on_pushButton_3_clicked()
{
    scene.clear();
    VykresliSpiralu(ui->verticalSlider->value(), QPoint(-50, -50), QPoint(50, -50));
}

void MainWindow::on_pushButton_4_clicked()
{
    scene.clear();\
    VykresliExcKruhy(ui->verticalSlider->value(), QPoint(0,0), 100);
}

void MainWindow::on_pushButton_5_clicked()
{
    scene.clear();
    VykresliStrom(ui->verticalSlider->value(), QPoint(10,0), QPoint(40,0), QPoint(40,30), QPoint(10, 30));
}

void MainWindow::on_pushButton_6_clicked()
{
    scene.clear();
    VykresliPicoid(ui->verticalSlider->value(), QPoint(0,0),QPoint(50,0),QPoint(50,50),QPoint(0,50));
}
