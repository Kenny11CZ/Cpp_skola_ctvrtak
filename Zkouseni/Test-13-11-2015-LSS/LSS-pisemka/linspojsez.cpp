#include "linspojsez.h"
#include "stdio.h"

LinSpojSez::LinSpojSez()
{
    prvni = NULL;
}

void LinSpojSez::Vypis()
{
    printf("\n");
    if(prvni == NULL)
    {
        printf("Nothing found in this LSS");
        return;
    }
    PrvekLSS *t = prvni;
    while (t != NULL) {
        printf("%d ", t->GetHodnota());
        t = t->GetUkDalsi();
    }
    printf("\n");
}

void LinSpojSez::PridatZacatek(int x)
{
    PrvekLSS *n = new PrvekLSS();
    n->SetHodnota(x);
    if(prvni == NULL)
    {
        n->SetUkDalsi(NULL);
        prvni = n;
    }
    else
    {
        n->SetUkDalsi(prvni);
        prvni = n;
    }
    printf("pridano %d\n", x);
}



