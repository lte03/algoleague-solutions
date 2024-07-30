#include <stdio.h>
#include <stdlib.h>

int solution(int m,int *A,int n);
int findMax(int *arr, int m);

int main() {
    int m,n;
    int* A = malloc(sizeof(int) * m);
    int required = 0;
    scanf("%d",&m);
    for(int i = 0;i < m;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&n);
    int answer = solution(m,A,n);
    printf("%d",answer);
    free(A);
	return 0;
}

int solution(int m, int *A, int n) {
    int total_candies_needed = 0;
    int max_candies = findMax(A, m);
    
    for (int i = 0; i < m; i++) {
        total_candies_needed += max_candies - A[i];
    }
    
    if (total_candies_needed > n) {
        return 0;
    }
    
    int remaining_candies = n - total_candies_needed;
    if (remaining_candies % m == 0) {
        return 1;
    } else {
        return 0;
    }
}

int findMax(int *arr,int m){
    int max = arr[0];
    for(int i = 0;i < m;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}