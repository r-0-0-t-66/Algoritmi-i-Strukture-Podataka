#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gen_arr(float *V, int n, float dg, float gg);
int sekv_pret(float *V, int n, float x);
void sort(float *V, int n);
int bin_pret(float *V, int n, float x);
void swap(float* a, float* b);
// dg + (float)rand() / RAND_MAX * (gg - dg)

int main() {
	time_t t1, t2;
	float x = 15;
	int n;
	scanf("%d", &n);
	float dg = 10;
	float gg = 30;

	float *V = NULL;
	V = (float*)calloc(n, sizeof(float));
	if (V == NULL)
		return 1;
	int size = sizeof(V) / sizeof(V[0]);
	gen_arr(V, n, dg, gg);
	sort(V, n);
	srand((unsigned)time(NULL));


	t1 = clock();
	
	bin_pret(V, n, x);

	t2 = clock();

	printf("Vrijeme trajanja je %dms\n",(t2 - t1));
	free(V);
	return 0;
}

void gen_arr(float *V, int n, float dg, float gg) {
	for (int i = 0; i < n; i++) {
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg);
	}
}

void swap(float* a, float* b) {
	float t = *a;
	*a = *b;
	*b = t;
}


void sort(float *V, int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (V[j] < V[min])
				min = j;
		}
		swap(&V[i], &V[min]);
	}
}

int sekv_pret(float* V, int n, float x) {
	for (int i = 0; i < n; i++) {
		if (V[i] == x)
			return i;
	}
	return -1;
}

int bin_pret(float* V, int n, float x) {
    int low = 0, high = n-1;
	if (low >= high) {
		int mid = low + (high - low) / 2;

		if (V[mid] == x)
			return mid;
			if (V[mid] > x)
				return bin_pret(V, n, mid - 1);

		return bin_pret(V, n, mid - 1);
	}
	return -1;
}