#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* convertToBinary(int number, int n);
void printBinary(int* binary, int n);

int main() {
    int n;
    scanf("%d", &n);
    int upBounce = pow(2, n);
    for (int i = 0; i < upBounce; i++) {
        int* binary = convertToBinary(i, n);
        printBinary(binary, n);
        free(binary);  
    }
    return 0;
}

int* convertToBinary(int number, int n) {
    int* binary = (int*)malloc(n * sizeof(int));
    int p = 0;
    if (number == 0) {
        for (int i = 0; i < n; i++) {
            binary[i] = 0;
        }
    }
    while (number > 0) {
        binary[n - p - 1] = number % 2;
        number /= 2;
        p++;
    }
    return binary;
}

void printBinary(int* binary, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}
