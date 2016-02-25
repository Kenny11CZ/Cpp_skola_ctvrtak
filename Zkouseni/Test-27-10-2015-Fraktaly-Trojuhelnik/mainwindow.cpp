#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    VykresliTrojuhelnik(1, QPointF(0,0), QPointF(100,0), QPointF(50,-75));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::VykresliTrojuhelnik(int n, QPointF a, QPointF b, QPointF c)
{
    if(n>0)
    {
        scene.addLine(a.x(), a.y(), b.x(), b.y());
        scene.addLine(b.x(), b.y(), c.x(), c.y());
        scene.addLine(c.x(), c.y(), a.x(), a.y());
        QPointF stredC = QPointF( (a.x()+b.x())/2, (a.y()+b.y())/2 );
        QPointF stredB = QPointF( (a.x()+c.x())/2 , (a.y()+c.y())/2 );
        QPointF stredA = QPointF( (b.x()+c.x())/2 , (b.y()+c.y())/2 );
        VykresliTrojuhelnik(n-1, a, stredC, stredB);
        VykresliTrojuhelnik(n-1, stredC, b, stredA);
        VykresliTrojuhelnik(n-1, stredB, stredA, c);

    }
}



void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    scene.clear();
    VykresliTrojuhelnik(position, QPointF(0,0), QPointF(100,0), QPointF(50,-75));
}
