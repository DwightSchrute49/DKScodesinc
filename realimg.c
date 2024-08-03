#include <stdio.h>

int result_real, result_imaginary; // Global variables to store the result

void add(int a, int b, int c, int d) {
    result_real = a + c;
    result_imaginary = b + d;
}

void subtract(int a, int b, int c, int d) {
    result_real = a - c;
    result_imaginary = b - d;
}

void multiply(int a, int b, int c, int d) {
    result_real = (a * c) - (b * d);
    result_imaginary = (a * d) + (b * c);
}

int main() {
    int choice, a, b, c, d;

    printf("Enter the real and imaginary parts of the first complex number (a + bi): ");
    scanf("%d%d", &a, &b);

    printf("Enter the real and imaginary parts of the second complex number (c + di): ");
    scanf("%d%d", &c, &d);

    printf("Choose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add(a, b, c, d);
            printf("Result of addition: %d + %di\n", result_real, result_imaginary);
            break;
        case 2:
            subtract(a, b, c, d);
            printf("Result of subtraction: %d + %di\n", result_real, result_imaginary);
            break;
        case 3:
            multiply(a, b, c, d);
            printf("Result of multiplication: %d + %di\n", result_real, result_imaginary);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

