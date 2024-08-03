#include <stdio.h>

#define MAXROWS 100
#define MAXCOLS 100

// Function prototypes
void accept(int M[][MAXCOLS], int r, int c);
void display(int M[][MAXCOLS], int r, int c);
void matrix_add(int A[][MAXCOLS], int B[][MAXCOLS], int C[][MAXCOLS], int r1, int c1, int r2, int c2);
void matrix_mul(int A[][MAXCOLS], int B[][MAXCOLS], int D[][MAXCOLS], int r1, int c1, int c2);

int main() {
    int A[MAXROWS][MAXCOLS], B[MAXROWS][MAXCOLS], C[MAXROWS][MAXCOLS], D[MAXROWS][MAXCOLS];
    int r1, c1, r2, c2;

    // Accepting dimensions of matrices A and B
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Validating dimensions for addition and multiplication
    if (r1 != r2 || c1 != c2) {
        printf("Matrices cannot be added or multiplied because of incompatible dimensions.\n");
        return 1;
    }

    // Accepting matrices A and B
    printf("Enter elements of matrix A:\n");
    accept(A, r1, c1);
    printf("Enter elements of matrix B:\n");
    accept(B, r2, c2);

    // Displaying matrices A and B
    printf("Matrix A:\n");
    display(A, r1, c1);
    printf("Matrix B:\n");
    display(B, r2, c2);

    // Performing addition if feasible
    if (r1 == r2 && c1 == c2) {
        printf("Matrix C (A + B):\n");
        matrix_add(A, B, C, r1, c1, r2, c2);
        display(C, r1, c1);
    }

    // Performing multiplication if feasible
    if (c1 == r2) {
        printf("Matrix D (A * B):\n");
        matrix_mul(A, B, D, r1, c1, c2);
        display(D, r1, c2);
    }

    return 0;
}

// Function to accept elements of a matrix
void accept(int M[][MAXCOLS], int r, int c) {
	int i,j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &M[i][j]);
        }
    }
}

// Function to display elements of a matrix
void display(int M[][MAXCOLS], int r, int c) {
	int i,j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
void matrix_add(int A[][MAXCOLS], int B[][MAXCOLS], int C[][MAXCOLS], int r1, int c1, int r2, int c2) {
	int i,j;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to perform matrix multiplication
void matrix_mul(int A[][MAXCOLS], int B[][MAXCOLS], int D[][MAXCOLS], int r1, int c1, int c2) {
	int i,j,k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            D[i][j] = 0;
            for (k = 0; k < c1; k++) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

