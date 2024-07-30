#include <stdio.h>

long getStickerNumber(long number);

int main() {
    long number;
    scanf("%ld", &number);
    long result = getStickerNumber(number);
    printf("%ld\n", result);
    return 0;
}

long getStickerNumber(long number) {
    long multiply = 1;
    while (number > 0) {
        if (number % 10 != 0) {
            multiply *= number % 10;
        }
        number /= 10;
    }
    if (multiply > 9) {
        return getStickerNumber(multiply);
    }
    return multiply;
}