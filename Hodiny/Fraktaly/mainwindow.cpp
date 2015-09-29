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
