#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

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

void MainWindow::murica(int height, int width)
{
    int rows = 13;
    int squareWidth = width*0.4;
    int squareHeight = (height/rows)*7;
    for(int i = 0; i<rows; ++i)
    {
        QPen pen = QPen(Qt::red);
        QBrush brush = QBrush(Qt::red);
        if(i%2)
        {
            pen = QPen(Qt::white);
            brush = QBrush(Qt::white);
        }
        scene.addRect(0,i*(height/rows),width, height/rows, pen, brush);
    }
    scene.addRect(0, 0, squareWidth, squareHeight, QPen(Qt::darkBlue), QBrush(Qt::darkBlue));
    for(int i = 0; i < 9; ++i)
    {
        int size = 6;
        if(i%2)
            size = 5;
        float offsetLeft = 15;
        float offsetTop = 10;
        float starSize = squareWidth/12;
        for(int j = 0; j < size; ++j)
        {
            if(size == 5)
                hvezda(2*starSize + j*2*starSize,
                       starSize+i*starSize,
                       starSize/2, Qt::white);
            else
                hvezda(starSize + j*2*starSize,
                       starSize+i*starSize,
                       starSize/2, Qt::white);
        }
    }
    //QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:\Users\dan.balarin\Desktop\eagle.jpg")));
    //scene->addItem(item);
}

void MainWindow::jiznanska(int height, int width)
{
    scene.addRect(0,0,width, height, QPen(Qt::red), QBrush(Qt::red));
    uhlopricky(40, Qt::white, 400, 600);
    uhlopricky(30, Qt::blue, 400, 600);
    float starSize = width/14/3;
    for(int i = 0; i < 7; ++i)
    {
        hvezda(i*6.5*starSize+starSize+16, i*4.2*starSize+starSize+12, starSize, Qt::white);
        if(i!=3)
            hvezda(i*6.5*starSize+starSize+16, height-(i*4.2*starSize+starSize)-12, starSize, Qt::white);
    }
}

void MainWindow::kuba(int height, int width)
{
    QImage image("cu.png");

    QGraphicsPixmapItem item( QPixmap::fromImage(image));
    scene.addItem(&item);
}

void MainWindow::hvezda(float x, float y, float length, QColor barva)
{
    int pocetVrcholu = 5;
    QLineF line(x, y, x, y-length);
    QPainterPath path;
    path.moveTo(line.p2());
    for(int i = 0; i < pocetVrcholu; ++i)
    {
        line.setAngle(line.angle() - 360 / (pocetVrcholu * 2));
        line.setLength(length * 0.4);
        path.lineTo(line.p2());
        line.setAngle(line.angle() - 360 / (pocetVrcholu * 2));
        line.setLength(length);
        path.lineTo(line.p2());
    }
    scene.addPath(path, QPen(barva), QBrush(barva));
}

void MainWindow::uhlopricky(int size, QColor barva, int height, int width)
{
    QPainterPath pruh;
    pruh.moveTo(0, height-size);
    pruh.lineTo(0, height);
    pruh.lineTo(size, height);
    pruh.lineTo(width, size);
    pruh.lineTo(width, 0);
    pruh.lineTo(width-size, 0);
    scene.addPath(pruh, QPen(barva), QBrush(barva));
    pruh.moveTo(0,0);
    pruh.lineTo(0, size);
    pruh.lineTo(width-size, height);
    pruh.lineTo(width, height);
    pruh.lineTo(width, height-size);
    pruh.lineTo(size, 0);
    scene.addPath(pruh, QPen(barva), QBrush(barva));
}

void MainWindow::flag(int height, int width)
{
    scene.addRect(-1, -1, width+2, height, QPen(Qt::black), QBrush(Qt::transparent));
    scene.addRect(-15, 0, 10, height+height/5, QPen(Qt::black), QBrush(Qt::black));
    scene.addEllipse(-5,5,5,5,QPen(Qt::black));
    scene.addEllipse(-5,height/2+5,5,5,QPen(Qt::black));
    scene.addEllipse(-5,height-5,5,5,QPen(Qt::black));
}

void MainWindow::on_muricaButton_clicked()
{
    scene.clear();
    flag(400,600);
    murica(400,600);
}

void MainWindow::on_jizanska_clicked()
{
    scene.clear();
    jiznanska(400,600);

}

void MainWindow::on_kuba_clicked()
{
    scene.clear();
    kuba(400,600);
}
