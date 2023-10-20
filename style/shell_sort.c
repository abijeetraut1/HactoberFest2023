#include <stdio.h>

// Function to perform shell sort
void shellSort(int arr[], int n) {
    // Start with a large gap and reduce it in each iteration
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform an insertion sort for elements at the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Move elements that are greater than temp
            // and are at least gap positions ahead of their current position
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Insert the current element at its correct position
            arr[j] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Perform shell sort
    shellSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
