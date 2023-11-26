#include<stdio.h>

// Calculate the greatest common divisor (GCD) using an iterative method
int findGCDIterative(int a, int b)
{
    int temp;

    // Implementing the Euclidean algorithm iteratively
    while(b != 0)
    {
        // Store the current value of b
        temp = b;

        // Update b with the remainder of the division
        b = a % b;

        // Set a to the previous value of b
        a = temp;
    }
    // The final value of 'a' is the GCD
    return a;
}

// Calculate the greatest common divisor (GCD) using a recursive method
int findGCDRecursive(int a, int b)
{
    // Base case: If 'b' becomes zero, return 'a' as the GCD
    if(b == 0)
    {
        return a;
    }
    else
    {
        // Recursively call the function with updated values of 'b' and 'a%b'
        return findGCDRecursive(b, a % b);
    }
}

int main()
{
    // Declare and initialize variables for user input
    int num1, num2;
    
    // Prompt user to enter a positive integer for 'num1'
    printf("Enter a positive integer for num1: \n");

    // Input from the user
    scanf("%d", &num1);

    // Ensure 'num1' is a positive number
    while(num1 <= 0)
    {
        printf("Invalid input. Please enter a positive integer for num1:\n");
        scanf("%d", &num1);
    }

    // Prompt user to enter a positive integer for 'num2'
    printf("Enter a positive integer for num2: \n");
    scanf("%d", &num2);

    // Ensure 'num2' is a positive number
    while(num2 <= 0)
    {
        printf("Invalid input. Please enter a positive integer for num2:\n");
        scanf("%d", &num2);
    }

    // Calculate and display the GCD using the iterative method
    printf("GCD of %d and %d using iteration method is: %d\n", num1, num2, findGCDIterative(num1, num2));

    // Calculate and display the GCD using the recursive method
    printf("GCD of %d and %d using recursive method is: %d\n", num1, num2, findGCDRecursive(num1, num2));

    return 0;
}
