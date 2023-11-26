#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables, initialize end points, and number of points
  int N = 12, i;
  double a = 0.0;
  double b = M_PI / 3.0;

  // Print the upper limit of the integral
  printf("b = x_12 = %f rads\n\n", b);

  // Calculate the width of each interval
  double width = (b - a) / (double)N;

  // Get values of f(x) = tan(x) for the end points and sum them up
  double X = tan(a) + tan(b);

  double x, y;
  double sum = X;

  // For loop: Get equidistant points, evaluate tan at each point, and store 2*tan(x) at each step
  for (i = 1; i < N; i++) {
    x = a + width * i;
    y = tan(x);
    // Multiply by the prefactor (2)
    sum += 2 * y;
  }

  // Calculate the approximate area of the integral using the trapezoidal rule
  double integral_approx = sum * width * 0.5;

  // Print the results
  printf("Approximate area of the integral from x=0 to pi/3 of the function tan(x) w.r.t x is:\n%.5f\n", integral_approx);
  printf("The exact solution is:\n%.5f\n", log(2.0));

  return 0;
}
