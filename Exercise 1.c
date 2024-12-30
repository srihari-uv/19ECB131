#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 8

void menu(void) {
    printf("\n1. Insert\n2. Delete\n3. Search\n4. Count the elements in the array\n5. Exit\nSelect your choice: ");
}

void insert(int array[], int *size, int value) {
    if (*size < MAX_SIZE) {
        array[*size] = value;
        (*size)++;
        printf("Value %d inserted successfully.\n", value);
    } else {
        printf("Array is full. Cannot insert more elements.\n");
    }
}

void delete(int array[], int *size, int value) {
    bool found = false;
    for (int i = 0; i < *size; i++) {
        if (array[i] == value) {
            found = true;
            for (int j = i; j < *size - 1; j++) {
                array[j] = array[j + 1];
            }
            (*size)--;
            printf("Value %d deleted successfully.\n", value);
            break;
        }
    }
    if (!found) {
        printf("Value %d not found in the array.\n", value);
    }
}

void search(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            printf("Value %d found at position %d.\n", value, i);
            return;
        }
    }
    printf("Value %d not found in the array.\n", value);
}

void count(int size) {
    printf("The array contains %d elements.\n", size);
}

int main(void) {
    int array[MAX_SIZE];
    int size = 0; // Current size of the array
    int choice, value;

    while (true) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(array, &size, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(array, &size, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(array, size, value);
                break;
            case 4:
                count(size);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Wrong option. Try again.\n");
        }
    }
}
