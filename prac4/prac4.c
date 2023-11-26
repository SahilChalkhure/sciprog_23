#include<stdio.h>
#include<math.h>

// Global constant for the number of intervals
int N = 12;

// Array to store tan values for each interval
double TanValues[13];

// Function to convert degrees to radians
double degtorad(double deg);

// Function to apply the trapezoidal rule for the integral approximation
double traprule(int N);

int main() {
    int i;
    double deg, rad;

    // Populate array with tan values for each 5-degree interval
    for (i = 0; i <= N; i++) {
        deg = i * 5.0;
        rad = degtorad(deg);
        TanValues[i] = tan(rad);
        // printf("TanValues[%d] = %f at x = %2.f degrees\n", i, TanValues[i], deg);
    }

    // Calculate the integral approximation using the trapezoidal rule
    double integral_approx = traprule(N);

    // Exact solution for the integral
    double integral_exact = log(2.0);

    // Print the results
    printf("Approximation of the integral from x = 0 to x = 60 of function tan(x) with respect to x is:\n%.5f\n", integral_approx);
    printf("The exact solution is:\n%.5f\n", integral_exact);

    return 0;
}

// Function to convert degrees to radians
double degtorad(double deg) {
    return (deg * M_PI) / 180.0;
}

// Function to apply the trapezoidal rule for the integral approximation
double traprule(int N) {
    int i;
    double width, area = TanValues[0] + TanValues[N];

    // Accumulate 2 * tan(x) values for the interior intervals
    for (i = 1; i < N; i++) {
        area += 2.0 * TanValues[i];
    }

    // Calculate the width of each interval in radians
    width = degtorad((60.0 - 0) / (2.0 * N));

    // Multiply by width to get the total area
    area = width * area;

    return area;
}
