#include <QCoreApplication>
#include "linspojsez.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LinSpojSez lss;
    lss.PridatZacatek(1);
    lss.PridatZacatek(2);
    lss.Vypis();
    return a.exec();
}
