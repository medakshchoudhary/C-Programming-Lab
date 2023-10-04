#include <stdio.h>

int main() {
    int selectedOption,a,b;
    printf("1. Square \n2. Rectangle \n3. Circle \nSelect : ");
    scanf("%d",&selectedOption);

    if (selectedOption==1){
        printf("1. Area of square \n2. Perimeter of square \nSelect : ");
        scanf("%d",&selectedOption);
        if (selectedOption==1){
            printf("Size of side of square : ");
            scanf("%d",&a);
            int area = a*a;
            printf("Area of side of square is %d",area);
        }
        else {
            printf("Size of side of square : ");
            scanf("%d",&a);
            int perimeter = 4*a;
            printf("Perimeter of side of square is %d",perimeter);
        }
    }
    
    else if (selectedOption==2){
        printf("1. Area of rectangle \n2. Perimeter of rectangle \nSelect : ");
        scanf("%d",&selectedOption);
        if (selectedOption==1){
            printf("Length of side of rectangle : ");
            scanf("%d",&a);
            printf("Breadth of side of rectangle : ");
            scanf("%d",&b);
            int area = a*b;
            printf("Area of side of rectangle is %d",area);
        }
        else {
            printf("Length of side of rectangle : ");
            scanf("%d",&a);
            printf("Breadth of side of rectangle : ");
            scanf("%d",&b);
            int perimeter = 2*(a+b);
            printf("Perimeter of side of rectangle is %d",perimeter);
        }
    }
    else{
        printf("1. Area of circle \n2. Perimeter of circle \nSelect : ");
        scanf("%d",&selectedOption);
        if (selectedOption==1){
            printf("Radius of the circle : ");
            scanf("%d",&a);
            float area = 3.14*a*a;
            printf("Area of side of circle is %f",area);
        }
        else {
            printf("Radius of the circle : ");
            scanf("%d",&a);
            float perimeter = 2*3.14*a;
            printf("Perimeter of side of circle is %f",perimeter);
        }
    }
    return 0;
}