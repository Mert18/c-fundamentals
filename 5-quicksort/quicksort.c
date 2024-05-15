#include <stdio.h>
#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);
void swap(int *a, int *b);

int main(void){
	int a[N], i;

	printf("Enter %d numbers to be sorted: ", N);
	for(i=0; i<N; i++)
		scanf("%d", &a[i]);

	quicksort(a, 0, N-1);

	printf("In sorted order: ");
	
	for(i=0; i<N; i++) 
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void quicksort(int a[], int low, int high) {
	if (low < high) {
		int pi = split(a, low, high);

		quicksort(a, low, pi-1);
		quicksort(a, pi+1, high);
	}
}

int split(int a[], int low, int high) {
	int pivot = a[high];
	int i = low-1;
	
	for(int j = low; j <= high-1; j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[high]);
	return i+1;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
