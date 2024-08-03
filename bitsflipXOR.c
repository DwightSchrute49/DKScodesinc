#include <stdio.h>

// Function to count the number of bits needed to be flipped
int countBits(int x, int y) {
    int count = 0;
    int xor_result = x ^ y; // Perform XOR of x and y
    
    // Count the number of set bits in xor_result
    while (xor_result > 0) {
        count += xor_result & 1; // Check if the least significant bit is set
        xor_result >>= 1; // Right shift xor_result
    }
    
    return count;
}

int main() {
    int x, y;
    
    // Input two non-negative numbers
    printf("Enter two non-negative numbers (separated by space): ");
    scanf("%d %d", &x, &y);
    
    // Error check for non-negative numbers
    if (x < 0 || y < 0) {
        printf("Both numbers should be non-negative.\n");
        return 1; // Exit with error
    }
    
    // Count the number of bits needed to be flipped
    int num_bits = countBits(x, y);
    
    // Print the result
    printf("Number of bits needed to convert %d to %d: %d\n", x, y, num_bits);
    
    return 0;
}

