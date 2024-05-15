#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int val) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = val;
    node->next = NULL;
    return node;
}

void Push(int val) {
    struct Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    printf("Element Pushed successfully!!!\n");
}

void Pop() {
    if (head == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        printf("Element %d Removed Successfully!!!\n", temp->data);
        free(temp);
    }
}

void Peek() {
    if (head == NULL) {
        printf("Stack Underflow!!!\n");
    } else {
        printf("%d is the topmost element\n", head->data);
    }
}

void Show() {
    if (head == NULL) {
        printf("Stack Underflow!!!\n");
    } else {
        struct Node *temp = head;
        printf("Stack Elements are: \n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, val;
    while (1) {
        system("cls");
        printf("1. Push.\n");
        printf("2. Pop.\n");
        printf("3. Peek.\n");
        printf("4. Show.\n");
        printf("5. Exit.\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Element to push: ");
                scanf("%d", &val);
                Push(val);
                break;
            case 2:
                Pop();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Show();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice...\n");
        }
        system("pause"); // press any key to continue
    }
    return 0;
}