#include <QCoreApplication>

int SectiLicheIndexy(int pole[], int velikost)
{
    int soucet = 0;
    for(int i = 0; i < velikost; i++) //for(int i = 1; i < velikost; i+2)
    {
        if(i%2==1)
            soucet += pole[i];
    }
    return soucet;
}

int main()
{
    int velikost = 10;
    int pole[10] = {10,1,25,3,4,8,56,9,68,52};
    printf("Soucet lichych prvku pole je: %d\n", SectiLicheIndexy(pole, velikost));
    return 0;
}
