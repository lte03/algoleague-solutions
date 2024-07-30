#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isBalanced(char* brackets, int n);

int main() {
    char brackets[200001];
    scanf("%s", brackets);
    int n = strlen(brackets);
    int answer = isBalanced(brackets, n);
    if(answer) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

int isBalanced(char* brackets, int n) {
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;
    for(int i = 0; i < n; i++) {
        if(brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[') {
            stack[++top] = brackets[i];
        } else {
            if(top == -1) {
                free(stack); 
                return 0;
            }
            char topElement = stack[top--];
            if((brackets[i] == ')' && topElement != '(') ||
               (brackets[i] == '}' && topElement != '{') ||
               (brackets[i] == ']' && topElement != '[')) {
                free(stack);
                return 0;
            }
        }
    }
    
    int balanced = (top == -1);
    free(stack);
    return balanced;
}