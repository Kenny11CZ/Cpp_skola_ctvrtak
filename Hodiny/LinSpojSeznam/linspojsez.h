#ifndef LINSPOJSEZ_H
#define LINSPOJSEZ_H
#include "prveklss.h"

class LinSpojSez
{
public:
    LinSpojSez();
    PrvekLSS *GetPrvni();
    void SetPrvni(PrvekLSS *prvni);
    void VypisLiche();
    int Soucet();
    int Soucin();
    float Prumer();
    int Soucet2n3();
    void Prohod13();
    void Prohod24();
    void Prohod23();

    void Pridej(int n);
    void VyplnLSS();
    void VypisLSS();
    PrvekLSS *GetPosledni();   
    void PridejNaZacatek(int cislo);
    void PridejNaKonec(PrvekLSS *posledni);
    void PridejNaKonec(int cislo);
    int PocetPrvku();
    void ZvysO1();
    //    void Prohozeni();
    void SmazPrvni();
    void SmazPosledni();
    void Smaz(int hodnota);
    void SmazLiche();
    void Prohozeni();
    void SmazKazdyDruhy();
    void SmazKazdyDruhy(int index, PrvekLSS *prvek);
    void SplitNaLicheASude(LinSpojSez &spojSude, LinSpojSez &spojLiche);

private:
    PrvekLSS *prvni;
};

#endif // LINSPOJSEZ_H
