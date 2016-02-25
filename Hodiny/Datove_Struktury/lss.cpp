#include "lss.h"
#include "prveklss.h"
#include "stdio.h"

LSS::LSS()
{
    SetPrvni(NULL);
}

PrvekLSS *LSS::GetPrvni()
{
    return this->prvni;
}

void LSS::SetPrvni(PrvekLSS *x)
{
    this->prvni = x;
}

void LSS::PridejNaZacatek(int cislo)
{
    PrvekLSS *novy = new PrvekLSS();
    novy->SetHodnota(cislo);
    novy->SetDalsi(prvni);
    prvni = novy;
}

void LSS::Vypln(int n)
{
    for(int i = 0; i < n; i++)
        PridejNaZacatek(i);
}

void LSS::Vypsat()
{
    PrvekLSS *dalsi = prvni;
    while(dalsi!=NULL)
    {
        printf("%d ", dalsi->GetHodnota());
        dalsi = dalsi->GetDalsi();
    }
    printf("\n");
}

