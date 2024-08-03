#include <stdio.h>


// Function to calculate and print Pascal's triangle
void printPascalTriangle(int n) {
    int coef = 1,i,j,space;
    for( i = 0; i < n; i++) {
        // Print spaces for alignment
        for( space = 1; space <= n-i; space++) {
            printf("  ");
        }

        for( j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;

            printf("%4d", coef);
        }
        printf("\n");
    }
}

int main() {
    int rows;

    // Input number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print Pascal's triangle
    printPascalTriangle(rows);

    return 0;
}


