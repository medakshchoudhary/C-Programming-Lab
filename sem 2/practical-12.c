#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    if (pq == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    pq->front = NULL;
    return pq;
}

void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (pq->front == NULL || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Element added to the priority queue\n");
}

void dequeue(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
        printf("Element dequeued\n");
    }
}

void peek(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Peeked element: %d (Priority: %d)\n", pq->front->data, pq->front->priority);
    }
}

void display(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = pq->front;
        printf("Priority Queue Elements:\n");
        while (temp != NULL) {
            printf("%d (Priority: %d)\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue();
    int choice;
    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                int val, p;
                scanf("%d %d", &val, &p);
                enqueue(pq, val, p);
                break;
            case 2:
                dequeue(pq);
                break;
            case 3:
                peek(pq);
                break;
            case 4:
                display(pq);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}