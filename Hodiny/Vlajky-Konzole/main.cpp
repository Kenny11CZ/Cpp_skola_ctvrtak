#include <stdio.h>
#include <windows.h>

void Cesko(int width, int height);
void CeskoBarevne(int width, int height);
void Ukol(int width, int height);
void DalsiNeco(int width, int height);
void VypisPole(char *pole);
void DebugBarvy();

int main(int argc, char *argv[])
{
    //DalsiNeco(20,20);
    //DebugBarvy();
    return 0;
}

void Cesko(int width, int height)
{
    int pocetHvezd = 0;
    char defZnak = '-';
    char specZnak = '*';
    for(int i = 0; i < height; ++i)
    {
        char znak = defZnak;
        if(i<=height/2)
            pocetHvezd++;
        else
            pocetHvezd--;
        if(i==height/2)
            defZnak = '+';
        for(int j = 0; j < width; ++j)
        {
            if(pocetHvezd>j)
                znak = specZnak;
            else
                znak = defZnak;
            printf("%c", znak);
        }
        printf("\n");
    }
}

void CeskoBarevne(int width, int height)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int pocetHvezd = 0;
    int defBarva = 255;
    int specBarva = 153;
    for(int i = 0; i < height; ++i)
    {
        int barva = defBarva;
        if(i<=height/2)
            pocetHvezd++;
        else
            pocetHvezd--;
        if(i==height/2)
            defBarva = 204;
        for(int j = 0; j < width; ++j)
        {
            if(pocetHvezd>j)
                barva = 153;
            else
                barva = defBarva;
            SetConsoleTextAttribute(hConsole, barva);
            printf(".");
        }
        printf("\n");
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void Ukol(int width, int height)
{
    int pocetHvezd = height/2;
    int maxHvezd = pocetHvezd;
    char defZnak = '-';
    char specZnak = '*';
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < maxHvezd; ++j)
        {
            if(j+1>maxHvezd-pocetHvezd)
                printf("%c", specZnak);
            else
                printf("%c", defZnak);
        }
        for(int j = 0; j < width-maxHvezd; ++j)
        {
            printf("%c", defZnak);
        }
        printf("\n");
        pocetHvezd--;
    }
}

void DalsiNeco(int width, int height)
{
    char defZnak = '0';
    char specZnak = '1';
    int pocetHvezd = height/2;
    //char pole[width+1][height];
    for(int i = 0; i < height; ++i)
    {
        if(i>height/2)
            pocetHvezd--;
        for(int j = 0; j < width; ++j)
        {
            char znak;
            if(width-j>pocetHvezd)
                znak = defZnak;
            else
                znak = specZnak;
            printf("%c", znak);
            //pole[j][i] = znak;
            //if(j-1==width)
                //pole[j+1][i] = '\n';
        }
        printf("\n");
    }
    //VypisPole(pole);
}

void VypisPole(char *pole)
{
    for(int i = 0; sizeof(pole)/sizeof(*pole); ++i)
    {
        printf("%c", pole[i]);
    }
}

void DebugBarvy()
{
    HANDLE  hConsole;
      int k;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // you can loop k higher to see more color choices
    for(k = 1; k < 255; k++)
    {
      SetConsoleTextAttribute(hConsole, k);
      printf("%3d  %s\n", k, "I want to be nice today!");
    }
}

