#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "hrana.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    idBodu = 0;
    ui->view->setScene(&scene);
    connect(ui->buttonPridejVrchol,SIGNAL(clicked()),
            this, SLOT(OnPridejVrchol()));
    connect(ui->buttonPridejHranu, SIGNAL(clicked()),
            this, SLOT(OnPridejHranu()));  
    connect(ui->buttonDijkstra,SIGNAL(clicked()),
            this, SLOT(OnDijkstra()));
    connect(ui->buttonClear,SIGNAL(clicked()),
            this, SLOT(OnClear()));
    connect(ui->buttonUplnyGraf,SIGNAL(clicked()),
            this, SLOT(OnUplnyGraf()));
    connect(ui->buttonNajdiKostru,SIGNAL(clicked()),
            this, SLOT(OnKostraGrafu()));
    connect(ui->buttonClearHrany,SIGNAL(clicked()),
            this, SLOT(OnClearHrany()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnPridejVrchol()
{
    int x = ui->spinX->value();
    int y = ui->spinY->value();
    ui->comboVrcholy->addItem("(" + QString::number(x) +
                           "," + QString::number(y) + ")");
    ui->comboVrcholStart->addItem(QString::number(idBodu));
    ui->comboVrcholKonec->addItem(QString::number(idBodu));
    Vrchol *b = new Vrchol(idBodu++,x,y);
    seznamVrcholu.append(b);
    scene.addItem(b);

    InicializujMat();
}

void MainWindow::OnPridejHranu()
{
    SetHrana(ui->comboVrcholStart->currentText().toInt(),
             ui->comboVrcholKonec->currentText().toInt());
}

void MainWindow::SetHrana(int idStart, int idKonec)
{
    //qDebug() << "hrana kostry " << idStart << idKonec;
    scene.addLine(QLineF(seznamVrcholu[idStart]->pos(),
                        seznamVrcholu[idKonec]->pos()));

    //Hrana h(seznamVrcholu[idStart], seznamVrcholu[idKonec]);
    //seznamHran.append(h);

    matSoused[idStart][idKonec] = true;
    matSoused[idKonec][idStart] = true;
}


void MainWindow::OnDijkstra()
{
    int idStart = ui->comboVrcholStart->currentText().toInt();
    int idKonec = ui->comboVrcholKonec->currentText().toInt();
    double vzdalenost = Dijkstra(idStart,idKonec);

    QGraphicsTextItem *text = scene.addText("Nejkratsi vzdalenost je " +
                                            QString::number(vzdalenost));
    text->setPos(seznamVrcholu[idKonec]->pos() + QPointF(10,0));
}

void MainWindow::OnClear()
{
    scene.clear();
    seznamHran.clear();
    seznamVrcholu.clear();
    InicializujMat();
    ui->comboVrcholKonec->clear();
    ui->comboVrcholStart->clear();
    ui->comboVrcholy->clear();
}

void MainWindow::OnUplnyGraf()
{
    for (int i = 0; i < seznamVrcholu.length(); ++i) {
        for (int j = i+1; j < seznamVrcholu.length(); ++j) {
            SetHrana(i,j);
        }
    }
}

void MainWindow::OnKostraGrafu()
{
    VytvorSeznamHran();
    for(int i = 0; i < seznamHran.length(); ++i)
    {
        if(!JeCyklus(seznamHran[i].GetStart()->GetId(),
                     seznamHran[i].GetKonec()->GetId(),
                     seznamHran[i].GetStart()->GetId()))
        {
            SetHrana(seznamHran[i].GetStart()->GetId(), seznamHran[i].GetKonec()->GetId());
            seznamHran[i].GetStart()->SetBarva("seda");
            seznamHran[i].GetKonec()->SetBarva("seda");
        }
    }
}

void MainWindow::OnClearHrany()
{
    scene.clear();
    seznamHran.clear();
    qDebug(QString::number(seznamVrcholu.length()).toLatin1());
    for(int i = 0; i < seznamVrcholu.length()-1; ++i)
    {
        scene.addItem(seznamVrcholu[i]);
    }
}


double MainWindow::Dijkstra(int idStart, int idKonec)
{
    SetBiluVrcholum();
    seznamVrcholu[idStart]->SetHodnota(0);

    while(idStart!=idKonec) {
        idStart = UpdateSousedu(idStart, idKonec);
    }
    return seznamVrcholu[idKonec]->GetHodnota();
}

void MainWindow::SetBiluVrcholum()
{
    for (int i = 0; i < seznamVrcholu.length(); ++i) {
        seznamVrcholu[i]->SetBarva("bila");
    }
}

void MainWindow::VytvorSeznamHran()
{
    for (int i = 0; i < seznamVrcholu.length(); ++i) {
        for (int j = i+1; j < seznamVrcholu.length(); ++j) {
            seznamHran.append(Hrana(seznamVrcholu[i], seznamVrcholu[j]));
        }
    }
    for(int i = 0; i < seznamHran.length() - 1; i++){
        for(int j = 0; j < seznamHran.length() - i - 1; j++){
            if(seznamHran[j+1].GetVaha() < seznamHran[j].GetVaha()){
                seznamHran.swap(j+1, j);
            }
        }
    }
}

bool MainWindow::JeCyklus(int idStart, int idKonec, int zarazka)
{
    if(idKonec == zarazka)
        return true;
    if(seznamVrcholu.length() < 3)
        return false;
    if(seznamVrcholu[idStart]->GetBarva() == "bila" || seznamVrcholu[idKonec]->GetBarva() == "bila")
        return false;

    for(int i = 0; i < seznamVrcholu.length(); i++)
        if(i != idStart && i != idKonec)
            if(matSoused[idKonec][i] == true)
                if(JeCyklus(idKonec, i, zarazka))
                    return true;
    return false;
}

///funkce spracuje jeden uzel. To znamena, ze vsem sousedum,
///  ktere jsou bile prepocita vzdalenost od seba. Na konci
/// oznaci uzel s idStart za sedy a vrati id uzlu souseda
/// s nejmemnsi hodnotou
int MainWindow::UpdateSousedu(int idStart,int idKonec)
{
    int minIndex = idKonec;
    for (int i = 0; i < seznamVrcholu.length(); ++i) {
        if(matSoused[idStart][i] == true) {//to znamena, ze vrchol
            //s id i sousedi s vrcholem s idStart
            if(seznamVrcholu[i]->GetBarva() != "seda") {
                //pokud jiz neni spracovany,
                //tak prepocitame vzdalenost
                if(seznamVrcholu[idStart]->GetHodnota() +
                       VahaHrany(idStart,i) <
                       seznamVrcholu[i]->GetHodnota()) {
                    seznamVrcholu[i]->SetHodnota(seznamVrcholu[idStart]->GetHodnota() +
                                              VahaHrany(idStart,i));
                    if(seznamVrcholu[i]->GetHodnota() <
                            seznamVrcholu[minIndex]->GetHodnota()) {
                        minIndex = i;
                    }
                }
            }
        }
    }
    seznamVrcholu[idStart]->SetBarva("seda");
    //mame vo vsech sousedech spravnu aktualnu vzdalenost
    return minIndex;
}

double MainWindow::VahaHrany(int idStart, int idKonec)
{
    return sqrt(pow(seznamVrcholu[idStart]->x() -
                    seznamVrcholu[idKonec]->x(),2) +
                pow(seznamVrcholu[idStart]->y() -
                    seznamVrcholu[idKonec]->y(),2));
}

void MainWindow::InicializujMat()
{//vytvorime matici, kde nejsou zadne hrany(vse jsou hodnoty false
    for (int i = 0; i < seznamVrcholu.length(); ++i) {
        for (int j = 0; j < seznamVrcholu.length(); ++j) {
            matSoused[i][j] = false;
        }
    }
}

