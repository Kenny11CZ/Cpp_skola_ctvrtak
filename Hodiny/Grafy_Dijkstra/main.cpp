#include "mainwindow.h"
#include <QApplication>

//1. Vytvorime rozhrani na pridavani bodu a seznam bodu
//2. Vytvorime hrany
//2a) Vytvorime tridu Hrana
//2b) Udelame funkci na vzdalenost dvou bodu
//3. Setridime hrany podle velikosti
//3.1 : Vytvorime matici sousednosti
//4. Kruskalkuv algoritmus
//4a)pridavani hrany
//4b)kontrola cyklu pomoci pruchodu do hloubky


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int *u1,u2;


    return a.exec();
}
