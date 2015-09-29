#include <stdio.h>
int krok = 0;
void Hanoj(int n, char start, char help, char end)
{

    if(n > 0)
    {
        Hanoj(n-1, start, end, help);
        krok++;
        printf("%d|%c -> %c \n", krok, start, end);
        Hanoj(n-1, help, start, end);
    }
}

int main()
{
    Hanoj(20, 'A', 'B', 'C');
    return 0;
}

