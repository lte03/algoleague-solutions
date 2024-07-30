#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int records[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&records[i]);
    }
    int count = 0;
    int max = records[0];
    for(int i = 1;i < n;i++){
        if(records[i] > max){
            count++;
            max = records[i];
        }
    }
    printf("%d",count);
    return 0;
}