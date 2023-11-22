#include<stdio.h>
void main(){

    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; 

    // Input 
    printf("Enter %d elements, one by one:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // Display
    printf("The elements in the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
        printf("\nThe largest element is: %d\n", max);

}