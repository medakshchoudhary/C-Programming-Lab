#include <stdio.h>

double add(double a, double b)
{
    return a + b;
}
double subtract(double a, double b)
{
    return a - b;
}
double multiply(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    if(b!=0)
    {
        return a / b;
    }
    else
    {
    printf("Error : cannot divide by zero");
    return 0;
    }
}    
int main()
{
    char operator;
    double num1,num2,result;
    printf("Enter an operator (+,-,*,/): ");
    scanf("%c",&operator);
    printf("Enter the First number :- ");
    scanf("%lf",&num1);
    printf("Enter the Second number :- ");
    scanf("%lf",&num2);
    switch(operator)
    {
        case '+':
        result = add(num1,num2);
        printf("Output is :- %lf", result);
        break;
        case '-':
        result = subtract(num1,num2);
        printf("Output is :- %lf", result);
        break;
        case '*':
        result = multiply(num1,num2);
        printf("Output is :- %lf", result);
        break;
        case '/':
        result = divide(num1,num2);
        printf("Output is :- %lf", result);
        break;
        default:
        printf("Invalid operator");
        return 1;
    }
    
}