#include <stdio.h>

int cifSoucet(int n)
{
    return n == 0 ? 0 : n % 10 + cifSoucet(n/10);
}

int main()
{
    int input;
    scanf("%d", &input);
    printf("Ciferny soucet cisla %d je %d\n", input, cifSoucet(input));
    return 0;
}

