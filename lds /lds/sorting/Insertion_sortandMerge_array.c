// Write a program that will take two arrays as input from the user, sort them using the
// insertion sort and then merge them into single resultant sorted array. The merging
// should be done only after sorting and the merging should be done in optimal fashion


#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to merge two sorted arrays into one sorted array
void merge(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge arrays while there are elements in both arrays
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from arr1
    while (i < n1) {
        result[k++] = arr1[i++];
    }

    // Copy any remaining elements from arr2
    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

// Main function
int main() {
    int n1, n2;

    // Input size of the first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int* arr1 = (int*)malloc(n1 * sizeof(int));

    // Input elements of the first array
    printf("Enter %d elements for the first array:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input size of the second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int* arr2 = (int*)malloc(n2 * sizeof(int));

    // Input elements of the second array
    printf("Enter %d elements for the second array:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Sort both arrays using insertion sort
    insertionSort(arr1, n1);
    insertionSort(arr2, n2);

    // Create a resultant array to hold the merged output
    int* result = (int*)malloc((n1 + n2) * sizeof(int));

    // Merge the sorted arrays
    merge(arr1, n1, arr2, n2, result);

    // Display the resultant sorted array
    printf("Merged sorted array:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr1);
    free(arr2);
    free(result);

    return 0;
}
