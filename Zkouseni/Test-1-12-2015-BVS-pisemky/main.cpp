#include <stdio.h>
#include "strom.h"

int main()
{
    Strom *s = new Strom();
    s->PridejPrvek(1);
    s->PridejPrvek(5);
    s->PridejPrvek(7);
    s->PridejPrvek(6);

    s->Vypis();
    printf("\nPocet prvku: %d", s->Length());
    printf("\nSoucet prvku: %d", s->Soucet());
    printf("\n");
    printf("\nPrumer prvku: %.1f", s->Prumer());
    printf("\n");
}
