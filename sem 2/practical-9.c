#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *createNode(){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &node->data);
    node->next = NULL;
    return node;
}

void createCircularList(){
    int n, i;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);
    struct Node *temp=NULL;
    for(i=0;i<n;i++){
        struct Node *newNode = createNode();
        if(head==NULL)
            head = newNode;
        else {
            temp->next = newNode;  
        }
        temp = newNode;
    }
    temp->next = head;
}

void displayList(){
    if(head==NULL)
    printf("List is empty!!!");
    else{
        struct Node *temp=head;
        do{
           printf("%d ", temp->data);
           temp=temp->next;
        }while(temp!=head);
    }
    printf("\n");
}

void insertNodeInBeg(){
    struct Node *newNode=createNode();
   if(head==NULL){
    head = newNode;
    newNode->next = head;
   }
   else{  
    newNode->next = head;
    head = newNode;
    struct Node *t = head->next;
    while(t->next != head->next){
        t=t->next;
    }
    t->next = newNode;
   }
}

void insertNodeInEnd(){
    struct Node *newNode=createNode();
    if(head==NULL){
     head = newNode;
     newNode->next = head;
    }
     else{
        struct Node *temp = head;
        do{
            temp=temp->next;
        }while(temp->next!=head);
        temp->next=newNode;
        newNode->next = head;
     }
}

void insertNodeAtAnyLoc() {
    if (head == NULL)
        printf("List is Empty!!!\n");
    else {
        int pos, count = 1;
        printf("Enter Position: ");
        scanf("%d", &pos);
        if (pos == 1) { 
            insertNodeInBeg();
        } else {
            struct Node *temp = head;
           do {
               if(count == pos-1)
               {
                break;
               }
            count++;
            temp = temp->next;
           } while (temp->next != head);
            if (temp->next == NULL)
                printf("Invalid Position!!!\n");
            else {
                struct Node *newNode = createNode();
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}

void deleteNodeAtAnyLoc(){
    int pos, count = 1;
        struct Node *temp = head;
        printf("Enter Position: ");
        scanf("%d", &pos);
        if (pos == 1) { // Delete at beginning
            head = head->next;
        } else {
            do{
               if(count == pos-1){
                 break;
               }
               count++;
               temp = temp->next;
            }while(temp->next != head);
            if (temp == NULL)
                printf("Invalid Position!!!\n");
            else {
                temp->next = temp->next->next;
            }
        }
    
}

void search(){
    if(head==NULL) printf("List Empty!!!\n");
    else{
        int num, flag=0;
        printf("Enter data to search: ");
        scanf("%d", &num);
        struct Node *temp = head;
        while(temp!=NULL){
            if(temp->data == num){
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag==1) printf("Found!!!\n");
        else printf("Not Found!!!\n");
    }
}

int main()
{
    createCircularList();
    int choice;
    while(1){
        system("cls");
        printf("1. Inset Node in Beginning\n");
        printf("2. Insert Node in End\n");
        printf("3. Insert Node at any position\n");
        printf("4. Delete Node From Given Position\n");
        printf("5. Search Node in list\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        
    switch(choice){
        case 1:
        insertNodeInBeg();
        break;
        case 2:
        insertNodeInEnd();
        break;
        case 3:
        insertNodeAtAnyLoc();
        break;
        case 4:
        deleteNodeAtAnyLoc();
        break;
        case 5:
        search();
        break;
        case 6:
        displayList();
        break;
        case 7:
        exit(0);
        break;
    }
   system("pause");
    }
    return 0;
}