#include "strom.h"
#include "stdio.h"

int main()
{
    Strom *s = new Strom();
    s->Fill();
    s->VPrint();
    //s->Print(s->GetKoren());
    printf("soucet je: %d\n", s->Sum());
    printf("pocet prvku je: %d\n", s->Lenght());
    printf("prumer je: %.1f\n", s->Avg());
    return 0;
}

