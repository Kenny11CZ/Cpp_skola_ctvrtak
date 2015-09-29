#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    int velikost = 8;
    for(int j = 0;j<velikost;j++)
        for(int i = 0;i<velikost;i++)
        {
            QBrush brush;
            if(i%2-j%2) //Magicka podminka
                brush = QBrush(QColor(0,0,0,255));
            scene.addRect(10*i,10*j-10,10,10,QPen(),brush);
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}
