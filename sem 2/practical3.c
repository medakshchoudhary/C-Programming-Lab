#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
   char str[100];
   char stack[100];
   int top = -1,i,len,flag=0;
   printf("Enter the expression : ");
   fgets(str,100,stdin);
len = strlen(str);
    for(int i=0;i<len;i++)
   {
    if(str[i] == '(' ||str[i] == '{' ||str[i] == '[')
    {
        top++;
        stack[top] = str[i];
    }
    
    else if(str[i] == ')' ||str[i] == '}' ||str[i] == ']')
    {
        char ch = stack[top];
        if(ch=='(')
           ch = ')';

        else if(ch=='{')
           ch = '}';
        
        else 
          ch = ']';
        
        if(ch == str[i]){
            top--;
        }
        else{
            flag=1;
            break;
        }
    }
   }

   if(flag==0&&top==-1)
         printf("Balanced !!!!\n");
   else 
         printf("Not Balanced !!!!\n");

         return 0;
}