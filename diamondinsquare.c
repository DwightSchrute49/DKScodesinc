#include <stdio.h>

void printDiamondInSquare(int n) {
    int i, j;

    // Upper half of the diamond
    for (i = 0; i <=n; i++) {
        for (j = 0; j <= n; j++) {
            if (j >= n / 2 - i && j <= n / 2 + i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }

    // Lower half of the diamond
    for (i = n - 2; i >= 0; i--) {
        for (j = 0; j <= n; j++) {
            if (j >= n / 2 - i && j <= n / 2 + i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the square (odd number): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    printDiamondInSquare(n);

    return 0;
}

