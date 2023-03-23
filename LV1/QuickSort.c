#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quickSort(float[], int, int, int);
int partition(float[], int, int, int);
int main(void){
    srand((unsigned)time(NULL));
    int n;
    float* niz;
    printf("Unesi broj eleemenata niza:");
    scanf("%d", &n);
    niz = (float*)malloc(n* sizeof(float));
    if (niz == NULL)
    {
        printf("MAtrica nije alocirana");
    }
    
    for (int i = 0; i < n; i++)
    {
        niz[i] = rand() % 1000;
    }
    quickSort(niz, n, 0, n-1);
    
    return 0;
}
void quickSort(float niz[], int n, int start, int end){
if (end <= start)
{
    return;
}

int pivot = partition(niz, n, start, end);
quickSort(niz, n, start, pivot-1);
quickSort(niz, n, pivot+1, end);

}

int partition(float niz[], int n, int start, int end){

int pivot = niz[end];
int i = start -1;
for (int j = start; j <= end-1; j++)
{
    if (niz[j] < pivot)
    {
        i++;
        int temp = niz[i];
        niz[i] = niz[j];
        niz[j] = temp;
    }
    
}
i++;
int temp = niz[i];
        niz[i] = niz[end];
        niz[end] = temp;


return i;
}