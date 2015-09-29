#include <stdio.h>

int cifSoucet(int n)
{
    return n < 10 ? n : n % 10 + cifSoucet(n/10);
}

int main()
{
    int cislo;
    scanf("%d", &cislo);
    printf("%d", cifSoucet(cislo));
    return 0;
}
