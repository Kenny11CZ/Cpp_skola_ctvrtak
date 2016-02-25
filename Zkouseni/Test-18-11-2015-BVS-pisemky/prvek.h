#ifndef PRVEK_H
#define PRVEK_H

class Prvek
{
public:
    Prvek();

    int GetHodnota();
    void SetHodnota(int hodnota);
    Prvek *GetLevy();
    void SetLevy(Prvek *ukLevy);
    Prvek *GetPravy();
    void SetPravy(Prvek *ukPravy);

    bool GetKonecRadku() const;
    void SetKonecRadku(bool value);   
    int PocetPotomku();

private:
    int hodnota;
    Prvek *ukLevy;
    Prvek *ukPravy;
    bool konecRadku;
};

#endif // PRVEK_H
