#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Insertion sort for linked lists (buckets)
Node* insertionSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* sorted = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void bucketSort(float arr[], int n) {
    // 1. Create Buckets
    Node** buckets = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. Distribute Elements
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * arr[i]); // Assuming elements are in range [0, 1)
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    // 3. Sort Buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
    }

    // 4. Gather Elements
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
