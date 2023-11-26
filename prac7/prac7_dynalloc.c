#include <stdio.h>
#include <stdlib.h>

// Allocate an integer array of size n
int *allocatearray(int n) {
    int *p;
    // Allocate memory for the array
    p = (int *)malloc(n * sizeof(int));
    return p;
}

// Fill the array with ones
void fillwithones(int *array, int n) {
    int i;
    // Iterate through the array and set each element to 1
    for (i = 0; i < n; i++) {
        array[i] = 1;
    }
}

// Print the elements of the array
void printarray(int *array, int n) {
    int i;
    // Iterate through the array and print each element
    for (i = 0; i < n; i++) {
        printf("a[%d]: %d\n", i, array[i]);
    }
}

// Deallocate the memory used by the array
void freearray(int *array) {
    // Free the allocated memory
    free(array);
}

int main() {
    int n, *a;

    // Get the size of the array from the user
    printf("Size of the array:\n");
    scanf("%d", &n);

    // Allocate memory for the array
    a = allocatearray(n);

    // Fill the array with ones
    fillwithones(a, n);

    // Print the elements of the array
    printarray(a, n);

    // Deallocate the memory used by the array
    freearray(a);

    // Set the pointer to NULL to avoid potential issues
    a = NULL;

    return 0;
}
