#include "strom.h"
#include <QList>
#include <stdio.h>
#include <QDebug>

Strom::Strom()
{
    koren = NULL;    
}

void Strom::PridejPrvek(int hodnota)
{
    Prvek *novy = new Prvek();
    novy->SetHodnota(hodnota);

    if(koren == NULL) {
        koren = novy;
    } else {
        Prvek *potomek = koren;
        Prvek *rodic;
        while(potomek != NULL) {
            rodic = potomek;
            if (potomek->GetHodnota() < hodnota) {
                potomek = potomek->GetPravy();
            } else {
                potomek = potomek->GetLevy();
            }
        }
        if(rodic->GetHodnota() < hodnota) {
            rodic->SetPravy(novy);
        } else {
            rodic->SetLevy(novy);
        }
    }
}

int Strom::Soucet()
{
    return Soucet(koren, 0);
}

int Strom::Soucet(Prvek *x, int soucet)
{
    if(x != NULL)
    {
        soucet += x->GetHodnota();
        soucet = Soucet(x->GetLevy(), soucet);
        soucet = Soucet(x->GetPravy(), soucet);
    }
    return soucet;
}

int Strom::Length()
{
    return Length(koren, 0);
}

int Strom::Length(Prvek *x, int pocet)
{
    if(x != NULL)
    {
        pocet++;
        pocet = Length(x->GetLevy(), pocet);
        pocet = Length(x->GetPravy(), pocet);
    }
    return pocet;
}

float Strom::Prumer()
{
    return (float)this->Soucet()/this->Length();
}

int Strom::Vypis()
{
    Vypis(koren);
}

int Strom::Vypis(Prvek *x)
{
    if(x != NULL)
    {
        printf("%d ", x->GetHodnota());
        Vypis(x->GetLevy());
        Vypis(x->GetPravy());
    }
}


