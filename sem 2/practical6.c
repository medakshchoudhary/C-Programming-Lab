#include <stdio.h>
#include <stdlib.h>
#define maxsize 1000
int queue[maxsize];
int front = -1,rear = -1;
int isfull()
{
    return rear == maxsize-1;
}
int isempty()
{
    return front == -1;
}
void Enqueue(value)
{
    if(isfull())printf("\nQueue Overflow\n");
    else
    {
        queue[++rear] = value;
        if(front==-1)
        front=rear;
        printf("\n%d is added in queue !!!!\n",value);
    }
}
int Dequeue()
{
    if(isempty()||front>rear)printf("\nQueue underflow\n");
    else
    {
        int value = queue[front++];
        if(front>rear)
        front=rear=-1;
        return value;
    }
}
void peek()
{
    if(isempty()||front>rear)
    printf("\nQueue is Empty!!!!\n");
    else {
    int value1;
    value1 = queue[front];
    if(value1>0)
    printf("\nValue in the queue is :- %d\n",value1);
    }
}
void display(){
    int i;
    if(isempty())
    printf("\nQueue is Empty !!!!\n");
    else {
        for(i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
    }
    printf("\n");
}
void main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    display();
    printf("\nDequeued item: %d\n",Dequeue());
    printf("\nDequeued item: %d\n",Dequeue());
    display();
    Enqueue(60);
    Enqueue(70);
    display();

}