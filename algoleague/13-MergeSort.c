#include <stdio.h>
#include <stdlib.h>

int count = 0;

void merge(int* array, int left, int mid, int right);
void mergeSort(int* array, int left, int right);

int main() {
    int N;
    scanf("%d", &N);
    int* numbers = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    int left = 0;
    int right = N - 1;
    mergeSort(numbers, left, right);
    for (int i = 0; i < N; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n%d\n", count);
    free(numbers);
    return 0;
}

void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = array[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
        count++;
    }
}
