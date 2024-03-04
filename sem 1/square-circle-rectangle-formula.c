#include <stdio.h>

int main() {
    double l,b,area,peri;
    // square
    printf("Enter the length of the side of the square and hit eneter: ");
    scanf("%lf", &l);
    area = l*l;
    peri = 4*l;
    printf("The area of square is %.2lf",area);
    printf("\nThe perimeter of square is %.2lf\n",peri);
    // rectangle
    printf("\nEnter the length of the side of the rectangle and hit enter: ");
    scanf("%lf", &l);
    printf("Enter the breadth of the side of the rectangle and hit enter: ");
    scanf("%lf", &b); 
    area = l*b;
    peri = 2*(l+b);
    printf("The area of rectangle is %lf\n",area);
    printf("The perimeter of rectangle is %lf\n",peri);
    // circle
    printf("\nEnter the radius of the circle below of which the area you want an hit enter : ");
    scanf("%lf", &l);
    area = 3.14*l*l;
    peri = 2*3.14*l;
    printf("Area of circle for radius %.2lf is %.2lf\n", l, area);
    printf("Perimeter of circle for radius %.2lf is %.2lf\n", l, peri); // .2 means only 2 decimal places will be displayed
    return 0;
}