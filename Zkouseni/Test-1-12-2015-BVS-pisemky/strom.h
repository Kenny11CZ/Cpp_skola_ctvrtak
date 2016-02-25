#ifndef STROM_H
#define STROM_H
#include "prvek.h"

class Strom
{
public:
    Strom();
    void PridejPrvek(int hodnota);
    int Soucet();
    int Soucet(Prvek *x, int soucet);
    int Length();
    int Length(Prvek *x, int pocet);
    float Prumer();
    int Vypis();
    int Vypis(Prvek *x);
    //void OznacKonceRadku(Prvek *prvek);

private:
    Prvek *koren;
    int soucet;
};

#endif // STROM_H
