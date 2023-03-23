#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binarySearch(int[], int, float);
int main(void){

    int n;
    int* niz;
    srand((unsigned)time(NULL));
printf("Unesi velicinu niza: ");
scanf("%d", &n);
 niz = (int*)malloc(n* sizeof(int));
if (niz == NULL)
{
    printf("Memorija nije alocirana");
    exit(0);
}

    for ( int i = 0; i < n; i++)
    {
        niz[i] = rand() % 1000;
      
    }

    int trazeniBroj;
    printf("Unesite broj koji trazite: ");
    scanf("%d", &trazeniBroj);
    printf("%d", binarySearch(niz, n, trazeniBroj));
    
return 0;
}


int binarySearch(int V[], int n, float x){
    int dg = 0, gg = n-1, mid;

    mid =  (gg + dg) / 2;   
    if(dg > gg){
        return -1;
    }
    if(V[mid] == x){
        return mid;
    }else if (V[mid] > x)
    {
        return binarySearch(V, n, mid - 1);
    }else{
        return binarySearch(V, n, mid+1);
    }        
}