#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    // Find the maximum element in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a count array to store the frequency of each element
    int *count = (int*) calloc(max + 1, sizeof(int));  // Initialize all elements to 0

    // Store the frequency of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the original array with sorted values
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Free the allocated memory for count array
    free(count);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

OUTPUT:

Original array: 4 2 2 8 3 3 1 
Sorted array: 1 2 2 3 3 4 8 
