#include <stdio.h>

int main() {
    int rows, coef = 1,i,j;

    // Input number of rows for Pascal's triangle
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &rows);

    // Iterate through each row
    for (i = 0; i < rows; i++) {
        // Print spaces to align triangle properly
        for (int space = 1; space <= rows - i; space++)
            printf("  ");

        // Calculate and print coefficients for each row
        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;

            printf("%4d", coef);
        }

        printf("\n");
    }

    return 0;
}

