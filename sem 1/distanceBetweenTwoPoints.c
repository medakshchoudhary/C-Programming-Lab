#include <stdio.h>
#include <math.h>

int main() {
    int x2,x1,y2,y1,distance;
    printf("Enter the points x2,x1,y2,y1 respectively : ");
    scanf("%d%d%d%d",&x2,&x1,&y2,&y1);
    distance = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    printf("Distance between these points is : %d",distance);
    return 0;
}