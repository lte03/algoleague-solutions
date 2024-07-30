#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int harunS = 0, samiS = 0;
    int n, k;
    scanf("%d %d", &n, &k);
    char *winner = malloc(sizeof(char)*(k+1));
    scanf("%s", winner);
    for (int i = 0; i < n; i++) {
        if (i < k) {
            if (winner[i] == 'H') {
                harunS++;
            } else {
                samiS++;
            }
        } else {
            if (harunS < samiS) {
                harunS++;
            } else if (samiS < harunS) {
                samiS++;
            } else {
                samiS++;
                harunS++;
            }
        }
    }
    if (harunS > samiS) {
        printf("Harun");
    } else if (samiS > harunS) {
        printf("Sami");
    } else {
        printf("Cilek");
    }
    free(winner);
    return 0;
}
