#include <stdio.h>

int solution(int N, int x, int y);

int main() {
    int N, x, y;
    scanf("%d", &N);
    scanf("%d %d", &x, &y);
    int answer = solution(N, x, y);
    printf("%d", answer);
    return 0;
}

int solution(int N, int x, int y) {
    int dp[N+1];
    dp[0] = 1;
    for (int i = 1; i < N + 1; i++) {
        dp[i] = 0;
    }
    for (int i = 0; i < N + 1; i++) {
        if (i - x >= 0) {
            dp[i] += dp[i - x];
        }
        if (i - y >= 0) {
            dp[i] += dp[i - y];
        }
    }
    return dp[N];
}
