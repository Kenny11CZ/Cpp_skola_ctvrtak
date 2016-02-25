#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "hrana.h"
#include "vrchol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void OnPridejVrchol();
    void OnPridejHranu();
    void OnDijkstra();
    void OnClear();
    void OnUplnyGraf();
    void OnKostraGrafu();
    void OnClearHrany();

public:
    double Dijkstra(int idStart, int idKonec);

    int UpdateSousedu(int idStart, int idKonec);
   // void OnNajdiKostru();
    void InicializujMat();
    //bool JeCyklus(int idStart, int idKonec, int zarazka);
    void SetHrana(int idStart, int idKonec);
    double VahaHrany(int idStart, int idKonec);
    void SetBiluVrcholum();

private:
    void VytvorSeznamHran();
    bool JeCyklus(int idStart, int idKonec, int zarazka);
   // void ObarviPodleMatice();


    Ui::MainWindow *ui;
    QGraphicsScene scene;
    int idBodu;
    QList<Vrchol*> seznamVrcholu;

    QList<Hrana> seznamHran;
    //bool **matSoused;
    bool matSoused[100][100];
};

#endif // MAINWINDOW_H
