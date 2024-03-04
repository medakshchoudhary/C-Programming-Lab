#include <stdio.h>
void main()
{
    struct Student
    {
        int rollno;
        int m1,m2,m3;
        int total;
    };
    int n,i;
    int fun(int,int,int);
    printf("Enter the no of students ");
    scanf("%d",&n);
    struct Student s[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the student Rollno and Marks(3 Subjects) ");
        scanf("%d",&s[i].rollno);
        scanf("%d",&s[i].m1);
        scanf("%d",&s[i].m2);
        scanf("%d",&s[i].m3);
        s[i].total=fun(s[i].m1,s[i].m2,s[i].m3);
    }
    printf("****STUDENT DETAILS****");
    for(i=0;i<n;i++)
    {
        printf("RollNo:%d\n",s[i].rollno);
        printf("Mark1:%d\n",s[i].m1);
        printf("Mark2:%d\n",s[i].m2);
        printf("Mark3:%d\n",s[i].m3);
        printf("Total:%d\n",s[i].total);
    }
}
int fun(int x,int y, int z)
{
    int tot = (x+y+z);
    return tot;
}