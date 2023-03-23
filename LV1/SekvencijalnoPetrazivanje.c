#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sekvencijalno(int, int[], int);
int main(void){
    
    int n, i;
    int* niz;
    srand((unsigned)time(NULL));

    printf("Unesite broj elemenata: ");
    scanf("%d", &n);
    niz = (int*)malloc(n * sizeof(int));

    if(niz == NULL){
        printf("Memorija nije alocirana");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        niz[i] = rand() % 10 +1;
    }
    int trazeniBroj;
    printf("Unesite broj koji trazite:");
    scanf("%d", &trazeniBroj);
    sekvencijalno(trazeniBroj, niz, n);
    

    return 0;
}

void sekvencijalno(int x, int niz[], int n){
int pronadjen = 0;

for ( int i = 0; i < n; i++)
{
    if (niz[i] == x)
    {
        printf("Trazeni broj nalazi se na %d mjestu",i+1);
        pronadjen = 1;
        break;
    }
    
}
if (pronadjen == 0)
{
    printf("Nije pronadjen trazeni broj");
}


}