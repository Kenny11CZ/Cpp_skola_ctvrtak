#ifndef HRANA_H
#define HRANA_H
#include "vrchol.h"

class Hrana
{
public:
    Hrana();
    Hrana(Vrchol *start, Vrchol *konec);
    Vrchol *GetStart();
    Vrchol *GetKonec();
    double GetVaha();

private:
    Vrchol *start;
    Vrchol *konec;
    double vaha;
};

#endif // HRANA_H
