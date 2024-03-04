#include <stdio.h>

int main()
{
    union student
    {
        int rollno;
        char name[50];
        float avg;
    };
    int n,i;
    union student s;
    printf("Enter the student Rollno :-\n");
    scanf("%d",&s.rollno);
    printf("\nStudent rollno:%d\n",s.rollno);
    printf("Enter the student name :-\n");
    scanf("%s",s.name);
    printf("\nStudent name:%s\n",s.name);
    printf("Enter the student average :-\n");
    scanf("%f",&s.avg);
    printf("\nStudent average:%f\n",s.avg);
    return 0;
}