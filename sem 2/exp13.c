#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *left;
    struct Node *right;
    int data;
};

struct Node *createNode() {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter Tree element: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertInLeft(struct Node *parent) {
    parent->left = createNode();
}

void insertInRight(struct Node *parent) {
    parent->right = createNode();
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);                                                          
    }
}

int search(struct Node *root, int val) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == val) {
        return 1; 
    }
    int foundLeft = search(root->left, val);
    int foundRight = search(root->right, val);
    return foundLeft || foundRight;
}

int main() {
    struct Node *root = createNode();//19
    insertInRight(root);//72
    insertInLeft(root->right);//12
    insertInLeft(root);//52
    insertInLeft(root->right->left);//32
    insertInRight(root->right->left->left);//5
    printf("preorder:  ");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    preorder(root);
    printf("\n");
    printf("inorder:   ");
    inorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    printf("\n");
    int val;
    printf("Enter value to search: ");
    scanf("%d", &val);
    if (search(root, val)==1) {
        printf("Element Found!\n");
    } else {
        printf("Element not found!\n");
    }
    return 0;
}
