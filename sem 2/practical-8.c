#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prv;
};

struct Node *head = NULL, *tail = NULL;
struct Node *temp;
struct Node *createNode(){
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->prv = NULL;
    temp->next = NULL;
    return temp;
}

void createList(){   //doubly linked list
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        struct Node *newNode = createNode();
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prv = tail;
        }
        tail = newNode;
    }
}

void displayList(){  //displaying in forward direction
    if(head==NULL) printf("List Empty\n");
    else{
        int c;
        printf("type:\n 1 for forward \n 2 for reverse \n");
        scanf("%d", &c);
        switch (c)
        {
        struct Node *temp;
        case 1:
            temp = head;
            while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
             }
            printf("\n");
            break;

        case 2:
            temp = tail;
            while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->prv;
            } 
            printf("\n");
            break;

        default:
        printf("Invalid choice\n");
            break;
        }
    }
}

void insertNodeInBeg(){
   struct Node *newNode = createNode();
   if(head == NULL){
    head = newNode;
    tail = newNode;
   }
   else{
      newNode->next = head;
      head->prv = newNode;
      head = newNode;
   }
}

void insertNodeInEnd(){
struct Node *newNode=createNode();
    if(tail==NULL){
      head = newNode;
      tail = newNode;
    }
     else{
       tail->next = newNode;
       newNode->prv = tail;
       tail = newNode;
     }
}

void insertNodeAtAnyLoc(){
   if(head == NULL) printf("List Empty\n");
   else{
      int pos;
      printf("Enter Position: ");
      scanf("%d", &pos);
      if(pos==1){
          insertNodeInBeg(); // If position is 1, insert at the beginning
      }
      else{
          int count = 1;
          struct Node *temp = head;
          while(temp!=NULL){
              if(count == pos)
                  break;
              else{
                  count++;
                  temp = temp->next;
              }
          }
          if(temp == NULL) printf("Invalid Position\n");
          else{
              struct Node *newNode = createNode(); 
              newNode->next = temp; 
              newNode->prv = temp->prv; 
              if(temp->prv != NULL){
                  temp->prv->next = newNode; 
              }
              temp->prv = newNode;
          }
      }
   }
}
struct Node *searchNode(int key){
    struct Node *current = head;
    while(current != NULL){
        if(current->data == key)
            return current;
        current = current->next;
    }
    return NULL; // Key not found
}
void deleteNode(int key){
    struct Node *toDelete = searchNode(key);
    if(toDelete == NULL){
        printf("Node not found\n");
        return;
    }
    if(toDelete == head){
        head = head->next;
        if(head != NULL)
            head->prv = NULL;
        free(toDelete);
        return;
    }
    if(toDelete == tail){
        tail = tail->prv;
        if(tail != NULL)
            tail->next = NULL;
        free(toDelete);
        return;
    }
    toDelete->prv->next = toDelete->next;
    toDelete->next->prv = toDelete->prv;
    free(toDelete);
    printf("Node deleted successfully\n");
}


int main()
{
    createList();
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
        //deleteNode();
        break;
        case 5:
        //searchNode();
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