#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsview.h"

//Skupina B

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    VykresliKruh(1, QPoint(0,0), 200);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::VykresliKruh(int n, QPointF stred, float velikost)
{
    if(n>0)
    {
        scene.addEllipse(stred.x(), stred.y(), velikost, velikost);
        VykresliKruh(n-1, QPointF(stred.x()+velikost*0.7/4, stred.y()+velikost*0.7/4), velikost*0.7);
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    scene.clear();
    VykresliKruh(arg1, QPointF(0,0), 200);
}
