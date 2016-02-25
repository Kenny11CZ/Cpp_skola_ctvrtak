#include "prvek.h"
#include <stdio.h>

Prvek::Prvek()
{
    hodnota = 0;
    ukLevy = NULL;
    ukPravy = NULL;
    konecRadku = false;
}

//Prvek::~Prvek() {
////    delete ukLevy;
////    delete ukPravy;
//}

int Prvek::GetHodnota()
{
    return hodnota;
}

void Prvek::SetHodnota(int hodnota)
{
    this->hodnota = hodnota;
}

Prvek *Prvek::GetLevy()
{
    return ukLevy;
}

void Prvek::SetLevy(Prvek *ukLevy)
{
    this->ukLevy = ukLevy;
}

Prvek *Prvek::GetPravy()
{
    return ukPravy;
}

void Prvek::SetPravy(Prvek *ukPravy)
{
    this->ukPravy = ukPravy;
}

bool Prvek::GetKonecRadku() const
{
    return konecRadku;
}

void Prvek::SetKonecRadku(bool value)
{
    konecRadku = value;
}

int Prvek::PocetPotomku()
{
    if(GetLevy() != NULL && GetPravy() != NULL) {
        return 2;
    } else if(GetLevy() == NULL && GetPravy() == NULL) {
        return 0;
    } else {
        return 1;
    }
}



