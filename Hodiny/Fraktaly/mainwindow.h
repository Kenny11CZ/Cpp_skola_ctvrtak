#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void VykresliTrojuhelnik(int n, QPoint a, QPoint b, QPoint C);
    void VykresliKriz(int n, QPoint a, int velikost);
    void VykresliSpiralu(int n, QPoint a, QPoint b);
    void VykresliExcKruhy(int n, QPoint a, int velikost);
    void VykresliStrom(int n, QPoint a, QPoint b, QPoint c, QPoint d);
    void VykresliPicoid(int n, QPoint a, QPoint b, QPoint c, QPoint d);
    void VykresliCtverec(int n, QRect a);
    void VykresliCtverec2(int n, int x, int y, int side);
    void VykresliStrom2(int n, QPointF startPoint, double lenght, double angle);
    void VykresliSachovnici(int vel, int num);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
};

#endif // MAINWINDOW_H
