#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 8

void displayMenu() {
    printf("\n--- Array Operations Menu ---\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Count elements\n");

    printf("Select your choice: ");
}

int getUserChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void insertElement(int array[], int *size, int value) {
    if (*size < MAX_SIZE) {
        array[*size] = value;
        (*size)++;
        printf("Value %d inserted successfully.\n", value);
    } else {
        printf("Error: Array is full. Cannot insert more elements.\n");
    }
}

void deleteElement(int array[], int *size, int value) {
    bool found = false;
    for (int i = 0; i < *size; i++) {
        if (array[i] == value) {
            found = true;
            for (int j = i; j < *size - 1; j++) {
                array[j] = array[j + 1];
            }
            (*size)--;
            printf("Value %d dele
