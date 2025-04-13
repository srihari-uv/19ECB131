#include <stdio.h>

int input[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4}; // Hardcoded input array

void menu() {
  printf("\n1. Insertion Sort\n9. Exit\n");
}

void print_array() {
  printf("\nElements after sorting are:\n");
  for (int i = 0; i < 10; i++)
    printf("%d\t", input[i]);
  printf("\n");
}

void insertion_sort() {
  for (int i = 1; i < 10; i++) {
    int element = input[i];
    int j = i - 1;
    while (j >= 0 && input[j] > element) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = element;
  }
}

int main(void) {
  int choice = 0;
  menu();
  printf("\nSelect the sorting technique: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\n*Insertion Sort*\n");
      insertion_sort();
      print_array();
      break;
    case 9:
      return 0;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}
