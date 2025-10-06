#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Global variables
int array[MAX];
int num = 0;

// Function prototypes
void insertion();
void deletion();
void searching();
void sorting();
void display();

int main() {
    int choice;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter %d elements:\n", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }

    printf("The array elements are:\n");
    for (int i = 0; i < num; i++) {
        printf("%d\n", array[i]);
    }

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insertion\n2. Deletion\n3. Searching\n4. Sorting\n5. Display\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                searching();
                break;
            case 4:
                sorting();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); // Correct usage of exit
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}

void insertion() {
    int number;
    if (num >= MAX) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    printf("Enter the number to be inserted: ");
    scanf("%d", &number);
    array[num] = number;
    num++;
    printf("Element inserted successfully.\n");
}

void deletion() {
    int index;
    if (num <= 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter the index of the element to delete (0 to %d): ", num - 1);
    scanf("%d", &index);

    if (index < 0 || index >= num) {
        printf("Invalid index.\n");
        return;
    }

    for (int j = index; j < num - 1; j++) {
        array[j] = array[j + 1];
    }
    num--;
    printf("Element deleted successfully.\n");
}

void searching() {
    int to_search, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &to_search);

    for (int i = 0; i < num; i++) {
        if (array[i] == to_search) {
            printf("%d found at position %d (index %d).\n", to_search, i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%d not found in the array.\n", to_search);
    }
}

void sorting() {
    int temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

void display() {
    if (num == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("The array elements are:\n");
    for (int i = 0; i < num; i++) {
        printf("%d\n", array[i]);
    }
}

