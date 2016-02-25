#include "prveklss.h"
#include "stdio.h"

PrvekLSS::PrvekLSS()
{
    this->SetHodnota(0);
    this->SetDalsi(NULL);
}

PrvekLSS::PrvekLSS(int hodnota)
{
    this->SetHodnota(hodnota);
    this->SetDalsi(NULL);
}

void PrvekLSS::SetHodnota(int x)
{
    this->hodnota = x;
}

int PrvekLSS::GetHodnota()
{
    return this->hodnota;
}

void PrvekLSS::SetDalsi(PrvekLSS *x)
{
    this->dalsi = x;
}

PrvekLSS *PrvekLSS::GetDalsi()
{
    return this->dalsi;
}

