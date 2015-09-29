#include <stdio.h>
int NSD(int x, int y)
{
    if(x<y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    for(int i = y; i > 0; i--)
    {
        if(x%i==0 && y%i==0)
            return i;
    }
}
int Delitelne(int pole[], int velikost, int delitel)
{
    //printf("velikost %d", (sizeof(pole)/sizeof(pole[0])));
    for(int i = 0; i<velikost; i++){
        if(pole[i]%delitel == 0)
            printf("%d je delitelne %d\n", pole[i], delitel);
    }
    return 0;
}

int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("NSD je %d\n",NSD(x, y));
    int pole[6] = {1,5,87,36,23,12};
    Delitelne(pole, 6, 6);
    return 0;
}

