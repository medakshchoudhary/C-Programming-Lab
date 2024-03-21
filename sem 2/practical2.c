#include <stdio.h>
#include <stdlib.h>
#define size 10
int stack[10];
int top = -1;
int isEmpty(){
    return (top==-1)?1:0;
}
int isFull(){
    return (top==size-1)?1:0;
}
void push(){
    int item;
    if(isFull()){
        printf("Stack Overflow !!!!\n");
        exit(0);
    }
    else{
        printf("Enter the value you want to push to the stack :- ");
        scanf("%d",&item);
        top +=1;
        stack[top] = item;
    }
}
void pop(){
    int val;
    if(isEmpty()){
        printf("Stack UndeFlow");
    }
    else {
        val = stack[top];
        top -=1;
        printf("\n%d is removed from the stack\n", val);
    }
}
void show(){
    if(isEmpty()){
        printf("Stack is empty\n");
    }
    else{
        int i;
        printf("ELements in the Stack\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

void main()
{
    push();
    push();
    push();
    show();
    pop();
    printf("\n");
    show();
}