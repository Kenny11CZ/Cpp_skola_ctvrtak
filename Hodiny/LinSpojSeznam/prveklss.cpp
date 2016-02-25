#include "prveklss.h"
#include "stdio.h"

PrvekLSS::PrvekLSS()
{
    hodnota = 0;
    ukDalsiPrvek = NULL;
}

PrvekLSS::PrvekLSS(int hodnota) {
    this->hodnota = hodnota;
    ukDalsiPrvek = NULL;
}

void PrvekLSS::SetHodnota(int hod)
{
    this->hodnota = hod;
}

int PrvekLSS::GetHodnota()
{
    return hodnota;
}

void PrvekLSS::SetUkDalsi(PrvekLSS *uk)
{
    this->ukDalsiPrvek = uk;
}

PrvekLSS *PrvekLSS::GetUkDalsi()
{
    return this->ukDalsiPrvek;
}
