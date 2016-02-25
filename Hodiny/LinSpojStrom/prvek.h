#ifndef PRVEK_H
#define PRVEK_H


class Prvek
{
public:
    Prvek();
    int GetValue();
    void SetValue(int x);

    Prvek *GetLeft();
    void SetLeft(Prvek *x);

    Prvek *GetRight();
    void SetRight(Prvek *x);

    bool IsLast();
    void SetLast(bool x);

private:
    int hodnota;
    Prvek *leva;
    Prvek *prava;
    bool last;

};

#endif // PRVEK_H
