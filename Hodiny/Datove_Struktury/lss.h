#ifndef LSS_H
#define LSS_H

#include "prveklss.h"

class LSS
{
public:
    LSS();
    PrvekLSS* GetPrvni();
    void SetPrvni(PrvekLSS *x);
    void PridejNaZacatek(int cislo);
    void Vypln(int n);
    void Vypsat();

private:
    PrvekLSS *prvni;
};

#endif // LSS_H
