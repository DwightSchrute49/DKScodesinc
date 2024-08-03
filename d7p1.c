#include <stdio.h>

// Recursive function to convert any base to decimal
int any_to_decimal(int n, int b1) {
    static int result = 0; // Static variable to store intermediate results
    
    if (n == 0) // Base case
        return result;
    
    int digit = n % 10; // Extract the rightmost digit
    if (digit >= b1) {
        printf("Error: Digit %d is out of range for base %d.\n", digit, b1);
        return -1; // Error code
    }
    
    result = result * b1 + digit; // Update result
    return any_to_decimal(n / 10, b1); // Recursive call
}

// Recursive function to convert decimal to any base
int decimal_to_any(int n, int b2) {
    static int result = 0; // Static variable to store intermediate results
    
    if (n == 0) // Base case
        return result;
    
    int digit = n % b2; // Extract the remainder
    result = result * 10 + digit; // Update result
    
    return decimal_to_any(n / b2, b2); // Recursive call
}

int main() {
    int b1, b2, num;
    
    // Accept base inputs
    do {
        printf("Enter the base b1 (between 2 and 10): "); // Ask for base b1
        scanf("%d", &b1); // Read input for b1
        printf("Enter the base b2 (between 2 and 10): "); // Ask for base b2
        scanf("%d", &b2); // Read input for b2
    } while (b1 < 2 || b1 > 10 || b2 < 2 || b2 > 10 || b1 == b2); // Ensure valid bases
    
    // Accept number input
    do {
        printf("Enter a non-negative number in base %d: ", b1); // Ask for number in base b1
        scanf("%d", &num); // Read input number
    } while (num < 0); // Ensure non-negative number
    
    // Convert to decimal if necessary
    if (b1 != 10) {
        num = any_to_decimal(num, b1); // Convert to decimal
        if (num == -1) // Error occurred
            return 1;
    }
    
    // Convert to base b2
    num = decimal_to_any(num, b2); // Convert to base b2
    
    // Display the result
    printf("Converted number in base %d: %d\n", b2, num); // Print the converted number
    
    return 0;
}

