#include <stdio.h>

int Soucet(int n, int a = 0)
{
    return n > 0 ? Soucet(n-1, a + n)  : a;
}

int main()
{
    int cislo;
    printf("Zadejte cislo: ");
    scanf("%d", &cislo);
    printf("Soucet od 0 do %d je %d\n", cislo, Soucet(cislo));
    return 0;
}

