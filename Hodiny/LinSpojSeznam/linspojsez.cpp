#include "linspojsez.h"
#include "prveklss.h"
#include "stdio.h"
#include <QDebug>

LinSpojSez::LinSpojSez()
{
    prvni = NULL;
}

PrvekLSS *LinSpojSez::GetPrvni()
{
    return prvni;
}

void LinSpojSez::SetPrvni(PrvekLSS *prvni)
{
    this->prvni = prvni;
}

void LinSpojSez::Pridej(int n)
{
    for (int i = 0; i < n; ++i) {
        PridejNaZacatek(i);
    }
}

void LinSpojSez::PridejNaZacatek(int cislo)
{
    PrvekLSS *novyPrvek = new PrvekLSS();
    novyPrvek->SetHodnota(cislo);
    novyPrvek->SetUkDalsi(prvni);
    prvni = novyPrvek;
}

void LinSpojSez::VypisLSS()
{    
    int soucet = 0;
    PrvekLSS *pom = prvni;
    while (pom != NULL) {
        printf("%d ", pom->GetHodnota());
        pom = pom->GetUkDalsi();
    }
    printf("\n");
}

void LinSpojSez::VypisLiche()
{        
    PrvekLSS *pom = prvni;
    while (pom != NULL) {
        if (pom->GetHodnota() % 2 != 0) {
            printf("%d ", pom->GetHodnota());
        }
        pom = pom->GetUkDalsi();
    }
    printf("\n");
}

int LinSpojSez::Soucet()
{    
    int soucet = 0;
    PrvekLSS *pom = prvni;
    while (pom != NULL) {
        soucet += pom->GetHodnota();
        pom = pom->GetUkDalsi();
    }
    return soucet;
}

int LinSpojSez::Soucin()
{
    int soucin = 0;
    PrvekLSS *pom = prvni;
    while (pom != NULL) {
        if(soucin == 0)
            soucin = pom->GetHodnota();
        soucin *= pom->GetHodnota();
        pom = pom->GetUkDalsi();
    }
    return soucin;
}

float LinSpojSez::Prumer()
{    
    float soucet = 0;
    float pocet = 0;
    PrvekLSS *pom = prvni;
    while (pom != NULL) {
        ++pocet;
        soucet += pom->GetHodnota();
        pom = pom->GetUkDalsi();
    }
    return soucet/pocet;
}

int LinSpojSez::Soucet2n3()
{
    int soucet = 0;
    PrvekLSS *pom = prvni;
    while (pom != NULL) {
        if(pom->GetHodnota() % 2 == 0 || pom->GetHodnota() % 3 == 0) {
            soucet += pom->GetHodnota();
        }
        pom = pom->GetUkDalsi();
    }
    return soucet;
}

void LinSpojSez::Prohod13()
{
    PrvekLSS *treti = prvni->GetUkDalsi()->GetUkDalsi();
    PrvekLSS *druhy = prvni->GetUkDalsi();
    prvni->SetUkDalsi(treti->GetUkDalsi());
    treti->SetUkDalsi(druhy);
    druhy->SetUkDalsi(prvni);
    prvni = treti;
}

PrvekLSS *LinSpojSez::GetPosledni()
{
    if(prvni == NULL) {
        return NULL;
    } else {
        PrvekLSS *pom = prvni;
        while(pom->GetUkDalsi() != NULL) {
            pom = pom->GetUkDalsi();
        }
        return pom;
    }
}

void LinSpojSez::VyplnLSS()
{
    for (int i = 0; i < 9; ++i) {
        PrvekLSS *prvek = new PrvekLSS();
        prvek->SetHodnota(i);
        if(prvni == NULL) {
            prvni = prvek;
        } else {
            PrvekLSS *posledni = GetPosledni();
            posledni->SetUkDalsi(prvek);
        }
    }
}

void LinSpojSez::PridejNaKonec(int cislo)
{
    PrvekLSS *novyPrvek = new PrvekLSS();
    novyPrvek->SetHodnota(cislo);

    if(prvni == NULL) {
        prvni = novyPrvek;
    } else {
        GetPosledni()->SetUkDalsi(novyPrvek);
    }
}

void LinSpojSez::PridejNaKonec(PrvekLSS *posledni)
{
    if(prvni == NULL) {
        prvni = posledni;
    } else {
        GetPosledni()->SetUkDalsi(posledni);
    }
    posledni->SetUkDalsi(NULL);
}


int LinSpojSez::PocetPrvku()
{
    PrvekLSS *pom = prvni;
    int pocet = 0;
    while (pom != NULL) {
        ++pocet;
        pom = pom->GetUkDalsi();
    }
    return pocet;
}

void LinSpojSez::ZvysO1()
{
    PrvekLSS *pom = prvni;
    while (pom != NULL) {
        pom->SetHodnota(pom->GetHodnota() + 1);
        pom = pom->GetUkDalsi();
    }
}

void LinSpojSez::SmazPrvni()
{
    PrvekLSS *druhy = prvni->GetUkDalsi();
    delete prvni;
    prvni = druhy;
}

void LinSpojSez::SmazPosledni()
{
    if(prvni != NULL) {// seznam neni prazdny
        if(prvni->GetUkDalsi() == NULL) {// je jednoprvkovy
            delete prvni;
            prvni = NULL;
        } else {//v sezname je 2 a vice prvku
            // ziskame predposledni prvek
            PrvekLSS *predposledni = prvni;
            while (predposledni->GetUkDalsi()->GetUkDalsi() != NULL) {
                predposledni = predposledni->GetUkDalsi();
            }
            // v pom mame predposledni prvek
            delete predposledni->GetUkDalsi();//zmaze posledni prvek
            predposledni->SetUkDalsi(NULL);
        }
    }
}

void LinSpojSez::Smaz(int hodnota)
{    

    PrvekLSS *pom = prvni;
    //zmazeme ted vsechny prvku na zacatku, ktere maju danu hodnotu
    while(pom != NULL && pom->GetHodnota() == hodnota) {
        pom = pom->GetUkDalsi();
        delete prvni;
        prvni = pom;
    }

    if(pom!=NULL) {//pokud aktualny spojak neni prazdnej
        while (pom->GetUkDalsi() != NULL) {//tak ho prochazime
            //a hledame prvky na smazani
            if(pom->GetUkDalsi()->GetHodnota() == hodnota) {
             //nasli sme prvek na smazani
            //v pom je predesly prvek od prku, ktery chceme mazat
                if (pom->GetUkDalsi()->GetUkDalsi() == NULL) {
                    //mazany prvek je posledni v sezname
                    delete pom->GetUkDalsi();
                    pom->SetUkDalsi(NULL);
                    break;
                } else { //mazani prvek neni posledni
                    //prvni moznost
                    PrvekLSS *pom1 = pom->GetUkDalsi()->GetUkDalsi();
                    delete pom->GetUkDalsi();
                    pom->SetUkDalsi(pom1);
                    //druha moznost
                    //PrvekLSS *pom1 = pom->GetUkDalsi();
                    //pom->SetUkDalsi(pom->GetUkDalsi()->GetUkDalsi());
                    //delete pom1;
                }
            } else {//kdyz nemazeme, tak se posuneme na dalsi prvek
                pom = pom->GetUkDalsi();
            }
        }
    }
}

void LinSpojSez::SmazLiche()
{
    PrvekLSS *pom = prvni;
    //vymazeme vsechny liche prvky na pocatku
    while(pom != NULL && pom->GetHodnota() % 2 == 1) {
        prvni = pom->GetUkDalsi();
        delete pom;
        pom = prvni;
    }
    if(pom!=NULL) {
        while(pom->GetUkDalsi() != NULL) {
            if(pom->GetUkDalsi()->GetHodnota() % 2 == 1) {
                PrvekLSS *pom1 = pom->GetUkDalsi()->GetUkDalsi();
                delete pom->GetUkDalsi();
                pom->SetUkDalsi(pom1);
            } else {
                pom = pom->GetUkDalsi();
            }

        }
    }
}

void LinSpojSez::Prohozeni()
{
    PrvekLSS *first = prvni;//prvni prvek ruseneho(puvodneho) poradi
    PrvekLSS *poslednyProhozeny = prvni;//posledny prvek v novem sezname
    PrvekLSS *next;
    if (prvni != NULL) {
        if(prvni->GetUkDalsi() == NULL) {
            return;
        }
        first = first->GetUkDalsi();
        while (first != NULL) {
            next = first->GetUkDalsi();
            first->SetUkDalsi(prvni);
            prvni = first;
            first = next;
        }
        poslednyProhozeny->SetUkDalsi(NULL);
    }

//    PrvekLSS *prvni = this->prvni;
//    PrvekLSS *druhy = prvni->GetUkDalsi();
//    PrvekLSS *treti = prvni;
//    prvni->SetUkDalsi(NULL);
//    while(treti!=NULL){
//        treti = druhy->GetUkDalsi();
//        druhy->SetUkDalsi(prvni);
//        prvni = druhy;
//        druhy = treti;
//    }
//    this->prvni = prvni;

}

void LinSpojSez::SmazKazdyDruhy()
{
    SmazKazdyDruhy(0,prvni);
}

void LinSpojSez::SmazKazdyDruhy(int index, PrvekLSS *prvek)
{
    if (prvek != NULL) {//po poslednym prvku
        if (index % 2 == 0) {
            return SmazKazdyDruhy(index + 1, prvek);
        } else {
            PrvekLSS *pom = prvek->GetUkDalsi();
            if(pom == NULL) {
                return;
            } else {
                //pom je prvek, ktery chceme mazat a promenna prvek
                // je prvek pred pom
                prvek->SetUkDalsi(prvek->GetUkDalsi()->GetUkDalsi());
                delete pom;
                return SmazKazdyDruhy(index + 1, prvek->GetUkDalsi());
            }
        }
    }
}

void LinSpojSez::SplitNaLicheASude(LinSpojSez &spojSude, LinSpojSez &spojLiche)
{
    PrvekLSS *sude = spojSude.GetPrvni();
    PrvekLSS *liche = spojLiche.GetPrvni();

    while(prvni != NULL) {
        if(prvni->GetHodnota() % 2 == 0) {
            if(sude != NULL) {//kdyz sudy seznam neni prazdny
                sude->SetUkDalsi(prvni);
                sude = sude->GetUkDalsi();              
            } else { //kdyz je prazdny
                sude = prvni;               
                spojSude.SetPrvni(sude);
            }
            prvni = prvni->GetUkDalsi();
            sude->SetUkDalsi(NULL);
        } else {
            if(liche != NULL) {
                liche->SetUkDalsi(prvni);
                liche = liche->GetUkDalsi();
            } else {
                liche = prvni;
                spojLiche.SetPrvni(liche);
            }
            prvni = prvni->GetUkDalsi();
            liche->SetUkDalsi(NULL);
        }
    }
}

void LinSpojSez::Prohod24()
{
//    PrvekLSS *prvn=prvni;
//    PrvekLSS *treti= prvni->GetUkDalsi()->GetUkDalsi();
//    prvn->GetUkDalsi()->SetUkDalsi(treti->GetUkDalsi()->GetUkDalsi());
//    treti->GetUkDalsi()->SetUkDalsi(prvn->GetUkDalsi());
//    prvn->SetUkDalsi(treti->GetUkDalsi());
//    treti->SetUkDalsi(prvn->GetUkDalsi()->GetUkDalsi());
//    prvn->GetUkDalsi()->SetUkDalsi(treti);

    PrvekLSS *druhy = prvni->GetUkDalsi();
    prvni->SetUkDalsi(druhy->GetUkDalsi()->GetUkDalsi());
    druhy->GetUkDalsi()->SetUkDalsi(druhy);
    druhy = druhy->GetUkDalsi();
    druhy->GetUkDalsi()->SetUkDalsi(prvni->GetUkDalsi()->GetUkDalsi());
    prvni->GetUkDalsi()->SetUkDalsi(druhy);
}

void LinSpojSez::Prohod23()
{//predpokladame, ze seznam ma alespon 3 prvky
    PrvekLSS *druhy = prvni->GetUkDalsi();
    PrvekLSS *ctvrty = druhy->GetUkDalsi()->GetUkDalsi();
    prvni->SetUkDalsi(druhy->GetUkDalsi());//prvni ukazuje na dtreti
    prvni->GetUkDalsi()->SetUkDalsi(druhy);//treti ukazuje na druhy
    druhy->SetUkDalsi(ctvrty);//druhy ukazuje na ctvrty
}
























