#include "strom.h"

int main()
{
    Strom *s = new Strom();
    s->PridejPrvek(1);
    s->PridejPrvek(2);
    s->PridejPrvek(8);
    s->PridejPrvek(5);
    s->PridejPrvek(9);
    s->VypisLichych();
    return 0;
}
