#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    printf("Enter the value of n :- ");
    scanf("%d", &n);
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)calloc(n,sizeof(int));
    if(arr1 == NULL||arr2 == NULL)
    {
    printf("Memory Error!\n");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
        *(arr1+i) = i;
        }
        for(int i=0;i<n;i++)
        {
        *(arr2+i) = n-i;
        }
    }
    int *arr3 = (int*)realloc(arr1,(n/2) *sizeof(int));
    int *arr4 = (int*)realloc(arr2,(2*n) *sizeof(int)); 
    if(arr3==NULL||arr4==NULL)
    {
        printf("Reallocation Failed!\n");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
        printf("%d\n",*(arr3+i));
        }
        printf("\n");
        for(int i=0;i<2*n;i++)
        {
        printf("%d\n",*(arr4+i));
        }
    }
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
}