#include "linspojsez.h"


//DU 26.10 pro 4Bi1. po prazdninach pisemka z fraktalu a udelat
//funkci na zmazani kazdeho licheho prvku v sezname
//DU 27.10 pro 4Ai2 smazani sudych prvku v sezname
//DU 23.10 4Ai1 vypsat liche cisla z LSS, pisemka z fraktalu
//
int main()
{
    LinSpojSez seznam;
    LinSpojSez sude;
    LinSpojSez liche;
    seznam.PridejNaKonec(2);
    seznam.PridejNaKonec(5);
    seznam.PridejNaKonec(3);
    seznam.PridejNaKonec(4);
    seznam.VypisLSS();
    seznam.Prohod23();
    seznam.VypisLSS();
    seznam.VypisLiche();
  //  printf("%d",seznam.Soucet2n3());
//    seznam.SplitNaLicheASude(sude,liche);
//    seznam.VypisLSS();
//    sude.VypisLSS();
//    liche.VypisLSS();

   // seznam.VypisLiche();
   // printf("%d",seznam.Soucet());
    //seznam.VypisLSS();
//    printf("\n%f", seznam.Prumer());

//    seznam.VypisLSS();


   // seznam.Prohod24();


//    LinSpojSez *sez = new LinSpojSez;
//    sez->VypisLSS();
//    LinSpojSez s1;
//    LinSpojSez s2;
    //seznam.SplitNaLicheASude(s1,s2);
   // s1.VypisLSS();
   // s2.VypisLSS();
    //seznam.PridejNaZacatek(50);
    //seznam.ZvysO1();
    //seznam.SmazPrvni();
    //  seznam.SmazPosledni();

    //seznam.SmazKazdyDruhy();

   // seznam.Prohozeni();
   // seznam.VypisLSS();

    return 0;
}
