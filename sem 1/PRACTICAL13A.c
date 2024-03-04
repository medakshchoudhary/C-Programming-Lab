#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fptr1,*fptr2;
    char filename[100],c;
    printf("Enter the filename to open for reading :- ");
    scanf("%s",filename);
    fptr1 = fopen(filename,"r");
    if(fptr1==NULL)
    {
        printf("File cant be opened\n");
        exit(0);
    }
    printf("\nEnter the filename to open for writing :- ");
    scanf("%s",filename);
    fptr2=fopen(filename,"w");
    if(fptr2==NULL)
    {
        printf("Cannot open file %s \n",filename);
        exit(0);
    }
    c = fgetc(fptr1);
    while(c!=EOF)
    {
        fputc(c,fptr2);
        c = fgetc(fptr1);
    }
    printf("\nContents copied to %s",filename);
    fclose(fptr1);
    fclose(fptr2);
}