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
    void murica(int height, int width);
    void jiznanska(int height, int width);
    void kuba(int height, int width);
    void hvezda(float x, float y, float length, QColor barva);
    void uhlopricky(int size, QColor barva, int height, int width);
    void flag(int height, int width);


private slots:
    void on_muricaButton_clicked();
    void on_jizanska_clicked();

    void on_kuba_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
};

#endif // MAINWINDOW_H
