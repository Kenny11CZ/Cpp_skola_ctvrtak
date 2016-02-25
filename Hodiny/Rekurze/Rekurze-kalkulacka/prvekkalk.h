#ifndef PRVEKKALK_H
#define PRVEKKALK_H
#include "qchar.h"

class PrvekKalk
{
public:
    PrvekKalk();
    PrvekKalk *GetLevy();
    PrvekKalk *GetPravy();
    QChar GetOperace();
    float GetCislo();
    void SetOperace(QChar x);
    void SetCislo(float x);
    void SetLevy(PrvekKalk *x);
    void SetPravy(PrvekKalk *x);



private:
    char operace;
    float cislo;
    PrvekKalk *levy;
    PrvekKalk *pravy;
};

#endif // PRVEKKALK_H
