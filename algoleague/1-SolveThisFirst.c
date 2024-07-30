#include <stdio.h>

long calc(long,long);

int main() {
    long a,b;
    scanf("%ld",&a);
    scanf("%ld",&b);
    long result = calc(a,b);
    printf("%ld",result);
	return 0;
}

long calc(long a,long b){
    return a + b;
}
