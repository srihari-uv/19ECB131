
#include <stdio.h>

int input[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4}; // Hardcoded input array

void menu() {
  printf("\n6. Heap Sort\n9. Exit\n");
}

void print_array() {
  printf("\nElements after sorting are:\n");
  for (int i = 0; i < 10; i++)
    printf("%d\t", input[i]);
  printf("\n");
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}

void heap_sort() {
  int n = 10;

  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(input, n, i);

  // Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--) {
    // Move current root to end
    int temp = input[0];
    input[0] = input[i];
    input[i] = temp;

    // Call max heapify on the reduced heap
    heapify(input, i, 0);
  }
}

int main(void) {
  int choice = 0;
  menu();
  printf("\nSelect the sorting technique: ");
  scanf("%d", &choice);

  switch (choice) {
    case 6:
      printf("\n*Heap Sort*\n");
      heap_sort();
      print_array();
      break;
    case 9:
      return 0;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}
