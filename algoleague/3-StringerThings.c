#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char s[n];
    scanf("%s", s);

    char r[n];
    int p = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            r[p] = s[i];
            p++;
        }
    }
    r[p] = '\0';
    
    printf("%s\n", r);
    return 0;
}
