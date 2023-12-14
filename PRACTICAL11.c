#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByReference(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 , num2 ;
    printf("Enter the value of num1: ");
    scanf("%d", &num1);
    printf("Enter the value of num2: ");
    scanf("%d", &num2);

    printf("Before swapping: num1 = %d, num2 = %d\n\n", num1, num2);

    swapByValue(num1, num2);
    printf("After swapping using pass by value: num1 = %d, num2 = %d\n", num1, num2);

    swapByReference(&num1, &num2);
    printf("After swapping using pass by reference: num1 = %d, num2 = %d\n\n", num1, num2);

    return 0;
}
