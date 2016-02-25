#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void VykresliVez(int n, float velikost, QPointF stred);


private slots:
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    int default_width = 150;
};

#endif // MAINWINDOW_H
