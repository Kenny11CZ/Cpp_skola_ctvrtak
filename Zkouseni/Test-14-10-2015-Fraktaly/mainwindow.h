#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void VykresliKruh(int n, QPointF stred, float velikost);
    QGraphicsScene scene;

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
