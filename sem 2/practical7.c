#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createnode(){
    struct Node *node =(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d",&node->data);
    node->next = NULL;
    return node;
}
void insertNodeInBeg(){
    struct Node *newnode = createnode();
    if(head==NULL) head = newnode;
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insertNodeInEnd(){
    struct Node *newnode = createnode();
    if(head==NULL) head = newnode;
    else
    {
        struct Node *temp = head;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = newnode;
    }
}
void insertNodeAtPosition() {
    if(head==NULL)
    {
        printf("Invalid Postion !!!!\n");
    }
    else
    {
        int pos,cnt=1;
        printf("Enter Postion : ");
        scanf("%d",&pos);
        if(pos==1)
        {
            struct Node *newnode = createnode();
            newnode->next = head;
            head = newnode;
        }
        else{
            struct Node *temp = head;
            while(temp->next!=NULL)
            {
                if(cnt==pos-1){
                    break;
                }
                cnt++;
                temp = temp->next;
            }
        if(temp->next==NULL)
        {
            printf("Invalid Postion !!!!\n");
        }
        else{
            struct Node *newnode = createnode();
            newnode->next = temp->next;
            temp->next = newnode;
        }
        }
    }
}
void deleteNodeAtPosition() {
    if (head == NULL)
    {
        printf("\nInvalid Postion\n");
        return;
    }
    else
    {
        int pos,cnt=1;
        printf("Enter Postion : ");
        scanf("%d",&pos);
        if(pos==1)
        {
            head = head->next;
        }
        else{
            struct Node *temp = head;
            while(temp->next!=NULL)
            {
                if(cnt==pos-1){
                    break;
                }
                cnt++;
                temp = temp->next;
            }
        
        if(temp->next==NULL)
        {
            printf("\nInvalid Postion !!!!\n");
        }
        else{
            temp->next = temp->next->next;
        }
        }
    }
}
void createlist(){
    int n,i;
    printf("Enter number of nodes :- ");
    scanf("%d",&n);
    struct Node *temp = NULL;
    for(i=0;i<n;i++)
    {
        struct Node *newNode = createnode();
        if(head==NULL) head = newNode;
        else temp->next = newNode;
        temp = newNode;
    }
}

int searchNode(int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void displaylist()
{
    system("clear");
    if(head==NULL) printf("\nList is Empty\n");
    else
    {    
    struct Node *temp = head;
    printf("\nList elements :- ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    }
    printf("\n");
}
int main()
{
    system("clear");
    createlist();
   while(1){
    printf("\n");
    printf("\n1. Insert Node In Begining\n");
    printf("\n2. Insert Node In End\n");
    printf("\n3. Insert Node At Any Position\n");
    printf("\n4. Delete Node From Given Position\n");
    printf("\n5. Search Node In List\n");
    printf("\n6. Display List\n");
    printf("\n7. Exit\n");
    int choice;
    printf("\nEnter your choice : \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insertNodeInBeg();
        break;
        case 2:
        insertNodeInEnd();
        break;
        case 3:
        insertNodeAtPosition();
        break;
        case 4:
        deleteNodeAtPosition();
        break;
        case 5:
        int val;
        printf("Enter the value : ");
        scanf("%d",&val);
        if(searchNode(val)) printf("\nFOUNDED\n");
        else printf("\nNOT FOUND\n");
        break;
        case 6:
        displaylist();
        break;
        case 7:
        exit(0);
        break;
    }
   }
   printf("\n");
   return 0;
}