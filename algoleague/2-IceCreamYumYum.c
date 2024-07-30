#include <stdio.h>

const int N  = 100000;
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i  = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int min = a[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            index = i;
        }
    }
    
    long sum = 0; 
    for(int i = 0;i < n;i++){
        if(i == index){
            continue;
        }
        else{
            sum += a[i];
        }
    }
    printf("%ld",sum);
    return 0;
}