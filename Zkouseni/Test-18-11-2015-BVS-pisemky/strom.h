#ifndef STROM_H
#define STROM_H
#include "prvek.h"

class Strom
{
public:
    Strom();
    void PridejPrvek(int hodnota);
    void VypisLichych();
    void VypisLichych(Prvek *x);

private:
    Prvek *koren;
};

#endif // STROM_H
