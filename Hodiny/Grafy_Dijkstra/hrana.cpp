#include "hrana.h"
#include <math.h>

Hrana::Hrana()
{
    start = new Vrchol(0,0,0);
    konec = new Vrchol(0,0,0);
    vaha = 0;
}

Hrana::Hrana(Vrchol *start, Vrchol *konec)
{
    this->start = start;
    this->konec = konec;

    vaha = sqrt(pow(this->start->x() - this->konec->x(),2) +
                pow(start->y()-konec->y(),2));
}

Vrchol *Hrana::GetStart()
{
    return start;
}

Vrchol *Hrana::GetKonec()
{
    return konec;
}

double Hrana::GetVaha()
{
    return vaha;
}


