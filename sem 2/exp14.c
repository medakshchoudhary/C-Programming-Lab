#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left;
    struct Node *right;
    int data;
};

struct Node *createNode(int val) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
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

void postorder(struct Node *root) {
    if (root != NULL) {
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
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

struct Node *deleteElement(struct Node *root, int key){   //algo: 1.Find element via search 2.Delete the node
   if(root == NULL){  //not return 0 as at sometime it will reach the end for NULL
    return root;
   }
   else if(key < root->data){
     root->left = deleteElement(root->left, key);
     return root;
   }
   else if(key > root->data){
    root->right = deleteElement(root->right, key);
    return root;
   }
   //search ends here
   else{
      //cases 1.with zero children 2.with one child 3.with two children 
       //case1.
    //   if(root->left == NULL && root->right == NULL){
    //     return NULL;                                   //this logic gets covered in case2
    //   }
      //.

      //case2..
      if(root->right == NULL){
        return root->left;
      }
      else if(root->left == NULL){
        return root->right;
      }
      //..

      //case3...
      else{
        struct Node *temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteElement(root->right ,temp->data);
        return root;
      }                                                                                             
   }
} 

int main() {
    int choice, valToFind, key;
    struct Node *root = NULL;
    while (1) {
        system("cls");
        printf("\n**********Binary Search Tree*********\n");
        printf("1. Insert Node in Binary Search Tree\n");
        printf("2. Pre-Order traversal \n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Search element\n");
        printf("6. Delete an element\n");
        printf("7. Exit\n\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &valToFind);
                root = insert(root, valToFind); // Update root after insertion
                break;
            case 2: 
                preorder(root);
                printf("\n");
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &valToFind);
                if (search(root, valToFind)) {
                    printf("%d found \n", valToFind);
                } else {
                    printf("%d not found \n", valToFind);
                }
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = deleteElement(root, key);
                  break;    
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
        system("pause");
    }
    return 0;
}
