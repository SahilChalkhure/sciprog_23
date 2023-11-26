#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// calculate factorial
int factorial(int n);

int main(void) {
    int i, order;
    double e, *terms;

    // Enter Polynomial Order
    printf("Enter the required polynomial order:\n");

    // Check if a valid integer is entered
    if (scanf("%d", &order) != 1) {
        printf("Error: Didn't enter a number.\n");
        return 1;
    }

    // Allocate space for terms array
    terms = malloc(order * sizeof(double));

    // Populate and print e terms for each order
    for (i = 0; i < order; i++) {
        terms[i] = 1.0 / (double)factorial(i + 1);
        printf("e term for order %d is %1.14lf\n", i + 1, terms[i]);
    }

    e = 1.0;

    // Sum up the terms to estimate e
    for (i = 0; i < order; i++) {
        e = e + terms[i];
    }

    // Free allocated memory
    free(terms);

    // Print the estimated value of e and the difference from the true value
    printf("Estimated e is %.10lf, with a difference of %e\n", e, e - exp(1.0));

    return 0;
}

// Function to calculate factorial
int factorial(int n) {
    // We check for a negative number
    if (n < 0) {
        printf("Error: Negative number passed to factorial.\n");
        return -1;
    } else if (n == 0) {
        // Base case: factorial of 0 is 1
        return 1;
    } else {
        // Recursive case: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}

/*
We can see from the output that incresing the polynomial order more it tends to be towards Infinity from order = 34
It is because of the numerical overflow.

*/