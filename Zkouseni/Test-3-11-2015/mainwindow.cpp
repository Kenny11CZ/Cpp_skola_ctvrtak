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
        QLineF t = QLineF(a,b);
        scene.addLine(t);
        t = QLineF(b,c);
        scene.addLine(t);
        t = QLineF(c,a);
        scene.addLine(t);
        QPointF stredAB = QPointF( (a+b)/2 );
        QPointF stredBC = QPointF( (b+c)/2 );
        QPointF stredCA = QPointF( (c+a)/2 );
        VykresliTrojuhelnik(n-1, a, stredAB, stredCA);
        VykresliTrojuhelnik(n-1, stredAB, b, stredBC);
        VykresliTrojuhelnik(n-1, stredBC, c, stredCA);
    }
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    scene.clear();
    VykresliTrojuhelnik(position, QPointF(0,0), QPointF(100,0), QPointF(50,-75));
}
