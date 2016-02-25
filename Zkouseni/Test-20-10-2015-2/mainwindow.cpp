#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    VykresliVez(1, default_width, QPointF(0,0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::VykresliVez(int n, float velikost, QPointF stred)
{
    if(n>0)
    {
        int height = 20;
        float width_coeficient = 0.8;

        scene.addRect(stred.x()-velikost/2,stred.y()-height/2,velikost, height);
        VykresliVez(--n,velikost*width_coeficient,QPointF(stred.x(),stred.y()-height));
    }
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    scene.clear();
    VykresliVez(position, default_width, QPointF(0,0));
}
