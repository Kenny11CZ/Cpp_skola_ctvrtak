#include <stdio.h>

void VypsatSude(int pole[], int velikost)
{
    for(int i = 0; i < velikost; i++)
    {
        if(pole[i]%2 == 0 && pole[i]!=0)
            printf("%d\n", pole[i]);
    }
}
int CifernySoucet(int cislo)
{
    int soucet = 0;
    while(cislo!=0)
    {
        soucet += cislo%10;
        cislo /= 10;
    }
    return soucet;
}


int main()
{
    int velikost = 10;
    int pole[10] = {10,2,5,4,8,36,68,7,0,21};

    //VypsatSude(pole, velikost);
    printf("%d", CifernySoucet(54));
    return 0;
}
