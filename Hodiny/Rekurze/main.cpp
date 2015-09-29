#include <stdio.h>

int faktSoucet(int n)
{
    return n <= 1 ? 1 : n+faktSoucet(n-1);
}

int cifSoucet(int n)
{
    return n == 0 ? 0 : n % 10 + cifSoucet(n/10);
}

int fibCisla (int n)
{
    return n <= 1 ? n : fibCisla(n-1) + fibCisla(n-2);
}

int fibCislaTri (int n)
{
    return n <= 1 ? n : fibCislaTri(n-1) + fibCislaTri(n-2) + fibCislaTri(n-3);
}

int faktSoucetPadesat (int n)
{
    return n < 50 ? 0 : n + faktSoucetPadesat(n-1);
}

int main(int argc, char *argv[])
{
    int cislo = 0;
    scanf("%d", &cislo);
    printf("%d\n",fibCislaTri(cislo));
    return 0;
}

