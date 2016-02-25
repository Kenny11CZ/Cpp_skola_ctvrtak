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

void Strom::VypisLichych()
{
    VypisLichych(this->koren);
}

void Strom::VypisLichych(Prvek *x)
{
    if(x != NULL)
    {
        if(x->GetHodnota()%2)
            printf("%d ", x->GetHodnota());
        VypisLichych(x->GetLevy());
        VypisLichych(x->GetPravy());

    }
}

