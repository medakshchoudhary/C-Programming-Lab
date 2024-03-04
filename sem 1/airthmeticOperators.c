#include <stdio.h>

int main() {
    int a,b,sum,sub,mul,div,rem;
    printf("Enter first number (a) : ");
    scanf("%d",&a);
    printf("Enter second number (b) : ");
    scanf("%d",&b);
    sum = a+b; sub = a-b; mul = a*b; div = a/b; rem = a%b;
    printf("\nSum of a and b = %d\n",sum);
    printf("Subtraction of a and b = %d\n",sub);
    printf("Multiplication of a and b = %d\n",mul);
    printf("Divison of a and b = %d\n",div);
    printf("Remainder of a and b = %d",rem);
    return 0;
}