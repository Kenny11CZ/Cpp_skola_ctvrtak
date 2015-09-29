#include <stdio.h>
#include <math.h>

void bubbleSort(int * array, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j+1] < array[j]){
                int tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void selectionSort(int * array, int size) {
     for (int i = 0; i < size - 1; i++) {
         int maxIndex = i;
         for (int j = i + 1; j < size; j++) {
             if (array[j] > array[maxIndex]) maxIndex = j;
         }
         int tmp = array[i];
         array[i] = array[maxIndex];
         array[maxIndex] = tmp;
     }
 }

void combSort(int * array, int size) {
    int swapped = 0;
    int gap = size;
    while (gap != 1 || swapped == 1) {

        gap = floor(gap / 1.33);
        swapped = 0;
        if (gap < 1) {
            gap = 1;
        }
        for (int i = 0; i + gap < size; i++) {
            if (array[i] < array[i + gap]) {
                int tmp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = tmp;
                swapped = 1;
            }
        }
    }
}

void insertionSort(int * array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int j = i + 1;
        int tmp = array[j];
        while (j > 0 && tmp > array[j-1]) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = tmp;
    }
}


void VypisPole(int pole[], int velikost)
{
    for(int i = 0; i<velikost; i++)
        printf("%d | ",pole[i]);
    printf("\n");
}

int main()
{
    int velikost = 10;
    int pole[10] = {2,5,4,1,9,6,3,8,7,0};
    VypisPole(pole, velikost);
    combSort(pole, velikost);
    VypisPole(pole, velikost);
    return 0;
}

