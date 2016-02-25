#include "prvek.h"
#include "stdio.h"

Prvek::Prvek()
{
    hodnota = 0;
    leva = NULL;
    prava = NULL;
    last = false;
}

int Prvek::GetValue()
{
    return hodnota;
}

void Prvek::SetValue(int x)
{
    this->hodnota = x;
}

Prvek *Prvek::GetLeft()
{
    return leva;
}

void Prvek::SetLeft(Prvek *x)
{
    this->leva = x;
}

Prvek *Prvek::GetRight()
{
    return prava;
}

void Prvek::SetRight(Prvek *x)
{
    this->prava = x;
}

bool Prvek::IsLast()
{
    return last;
}

void Prvek::SetLast(bool x)
{
    last = x;
}

