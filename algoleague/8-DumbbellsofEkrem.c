#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int weights[N+1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &weights[i]);
        weights[i] += weights[i-1];
    }

    for (int i = 0; i < Q; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        int totalWeight = weights[R] - weights[L - 1];
        printf("%d\n", totalWeight);
    }
    return 0;
}