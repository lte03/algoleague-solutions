#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    long m;
    scanf("%d %ld", &n, &m);

    int **A = (int**)malloc(sizeof(int*) * n);
    for(int i = 0;i < n;i++){
        A[i] = (int*)malloc(sizeof(int) * n);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }

    for(long i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        A[u-1][v-1] = 1;
        A[v-1][u-1] = 1;
    }

    int counts[n];
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 1) {
                count++;
            }
        }
        counts[i] = count;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", counts[i]);
    }
    for(int i = 0;i < n;i++){
        free(A[i]);
    }
    free(A);
    return 0;
}