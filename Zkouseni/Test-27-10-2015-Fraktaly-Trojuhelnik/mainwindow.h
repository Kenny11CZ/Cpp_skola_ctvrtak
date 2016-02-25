#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void VykresliTrojuhelnik(int n, QPointF a, QPointF b, QPointF c);

private slots:
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
};

#endif // MAINWINDOW_H
