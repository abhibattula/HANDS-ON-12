#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

struct DynamicArray {
    int *data;
    int size;
    int capacity;
};

// Function to initialize a dynamic array
void initDynamicArray(struct DynamicArray *arr) {
    arr->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
}

// Function to resize the dynamic array
void resizeDynamicArray(struct DynamicArray *arr) {
    arr->capacity *= 2;
    arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
}

// Function to push an element into the dynamic array
void push(struct DynamicArray *arr, int value) {
    if (arr->size == arr->capacity)
        resizeDynamicArray(arr);
    
    arr->data[arr->size++] = value;
}

// Function to pop an element from the dynamic array
int pop(struct DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Dynamic array is empty!\n");
        return -1;
    }

    return arr->data[--arr->size];
}

// Function to search for a value in the dynamic array
bool search(struct DynamicArray *arr, int value) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == value) {
            return true;
        }
    }
    return false;
}

// Function to print the dynamic array
void printDynamicArray(struct DynamicArray *arr) {
    printf("Dynamic Array: [ ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("]\n");
}

int main() {
    struct DynamicArray arr;
    initDynamicArray(&arr);

    int choice, value, poppedValue, searchValue;
    bool found;

    while (1) {
        printf("\nDynamic Array Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&arr, value);
                break;
            case 2:
                poppedValue = pop(&arr);
                if (poppedValue != -1)
                    printf("Popped value: %d\n", poppedValue);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &searchValue);
                found = search(&arr, searchValue);
                if (found)
                    printf("Value %d found in dynamic array.\n", searchValue);
                else
                    printf("Value %d not found in dynamic array.\n", searchValue);
                break;
            case 4:
                printDynamicArray(&arr);
                break;
            case 5:
                printf("Exiting program.\n");
                free(arr.data); // Free memory
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
