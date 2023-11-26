#include <stdio.h>
#include <math.h>

// Function to calculate arctanh using the Maclaurin series with precision delta
double arctanh1(const double x, const double delta);

// Function to calculate arctanh using the built-in logarithmic function
double arctanh2(const double x);

int main() {
    double delta, x;

    // Prompt user for precision value
    printf("Enter the precision for the Maclaurin Series: \n");
    scanf("%lf", &delta);

    // Initialize arrays to store arctanh values for comparison
    int length = 1000;
    double tan1[length];
    double tan2[length];

    // Loop through a range of x values and compare arctanh values
    int j = 0;
    x = -0.9;
    while (x <= 0.9 && j < length) {
        tan1[j] = arctanh1(x, delta);
        tan2[j] = arctanh2(x);
        printf("The difference at x=%lf between them is %.10lf.\n", x, fabs(tan1[j] - tan2[j]));
        j++;
        x = x + 0.01;
    }

    return 0;
}

// Function to calculate arctanh using the Maclaurin series with precision delta
double arctanh1(const double x, const double delta) {
    double arcTan = 0;
    double elem, val;
    int n = 0;

    do {
        val = 2 * n + 1;
        elem = pow(x, val) / val;
        arcTan += elem;
        n++;
    } while (fabs(elem) >= delta);

    return arcTan;
}

// Function to calculate arctanh using the built-in logarithmic function
double arctanh2(const double x) {
    return (log(1 + x) - log(1 - x)) / 2;
}
