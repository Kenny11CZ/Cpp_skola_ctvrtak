#ifndef STROM_H
#define STROM_H
#include "prvek.h"

class Strom
{
public:
    Strom();
    void AddElement(int val);
    Prvek *GetKoren();
    void Fill();
    void Print(Prvek *x);
    void VPrint();
    int Sum();
    int Lenght();
    float Avg();

private:
    Prvek *koren;
};

#endif // STROM_H
