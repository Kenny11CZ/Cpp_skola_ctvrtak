#include "prvekkalk.h"
#include "stdio.h"
#include "qchar.h"

PrvekKalk::PrvekKalk()
{
    this->levy = NULL;
    this->pravy = NULL;
    this->operace = '';
    this->cislo = 0;
}

PrvekKalk *PrvekKalk::GetLevy()
{
    return levy;
}

PrvekKalk *PrvekKalk::GetPravy()
{
    return pravy;
}

QChar PrvekKalk::GetOperace()
{
    return operace;
}

float PrvekKalk::GetCislo()
{
    return cislo;
}

void PrvekKalk::SetOperace(QChar x)
{
    operace = x;
}

void PrvekKalk::SetCislo(float x)
{
    cislo = x;
}

void PrvekKalk::SetLevy(PrvekKalk *x)
{
    levy = x;
}

void PrvekKalk::SetPravy(PrvekKalk *x)
{
    pravy = x;
}

