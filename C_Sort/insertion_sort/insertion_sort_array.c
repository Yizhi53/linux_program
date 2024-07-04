#include <math.h>
#include <stdio.h>

/*
 * Best case : O(n)
 * Average case : O(n^2)
 * Worst case : O(n^2)
 * Auxiliary Space: O(1)
 */

void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j -= 1;
    }

    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(int);
     
  printArray(arr, n);
  insertionSort(arr, n);
  printArray(arr, n);

  return 0;
}