#include <stdio.h>
void NecoFunkce(int width);
int main()
{
    int width = 26;
    NecoFunkce(width);
    return 0;
}
void NecoFunkce(int width)
{
    int height = width;
    int pocetHvezd = 0;
    char defZnak = '.';
    char specZnak = '*';
    for(int i = 0; i < height; ++i)
    {
        if(i<height/2)
            pocetHvezd++;
        for(int j = 0; j < width; ++j)
        {
            char znak;
            if(height-j<=pocetHvezd)
                znak = specZnak;
            else
                znak = defZnak;
            printf("%c", znak);
        }
        printf("\n");
    }
}

