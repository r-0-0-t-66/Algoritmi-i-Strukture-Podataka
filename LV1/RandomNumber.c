#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void randNum(float[], int, int, int);
int main(void){

    float* V;
    int n;
    printf("Unesite velicinu niza:");
    scanf("%d", &n);
    V=(float*)malloc(n * sizeof(float));

    randNum(V, n, 100, 200);
return 0;
}

void randNum(float V[], int n, int dg, int gg){
srand((unsigned)time(NULL));

for ( int i = 0; i < n; i++)
{
    V[i] = dg + rand() / (RAND_MAX / (gg - dg + 1)+1);
    printf("Random brojevi: %f", V[i]);
}

}