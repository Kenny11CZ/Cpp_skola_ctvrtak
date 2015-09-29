#include <stdio.h>
#include <math.h>

bool Find(int pole[], int velikost, int hledane)
{
    for(int i = 0; i < velikost; i++)
        if(pole[i]==hledane)
            return true;
    return false;
}

int FindRecursion(int pole[], int velikost, int hledane, int start, int konec)
{
    if(start>konec || hledane > pole[velikost-1])
        return 0;
    int stred = (start + konec)/2;
    if(pole[stred] == hledane)
        return stred;
    else if(pole[stred] > hledane)
        return FindRecursion(pole, velikost, hledane, start, stred-1);
    else
        return FindRecursion(pole, velikost, hledane, stred + 1, konec);
}

int main()
{
    int velikost = 5;
    int pole[5] = {5,8,15,30,45};
    int hledane = 65;



    printf("Obsahuje pole prvek? %d\n", FindRecursion(pole, velikost, hledane, 0, velikost));


    return 0;
}

