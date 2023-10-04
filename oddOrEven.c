#include <stdio.h>

int main() {
    int numberEntered;
    printf("Enter number to check for odd or even: ");
    scanf("%d", &numberEntered);
    if(numberEntered%2 == 0) {
        printf("Number entered is even");
    }
    
    if(numberEntered%2 == 1) {
        printf("Number entered is odd");
    }
    
    return 0;
}