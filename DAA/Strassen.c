#include <stdio.h>
#include <stdlib.h>

void add(int **A, int **B, int **C, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int **A, int **B, int **C, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

int **allocateMatrix(int size)
{
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        matrix[i] = calloc(size, sizeof(int));
    return matrix;
}

void freeMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    free(matrix);
}

void strassen(int **A, int **B, int **C, int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int **A11 = allocateMatrix(newSize), **A12 = allocateMatrix(newSize);
    int **A21 = allocateMatrix(newSize), **A22 = allocateMatrix(newSize);
    int **B11 = allocateMatrix(newSize), **B12 = allocateMatrix(newSize);
    int **B21 = allocateMatrix(newSize), **B22 = allocateMatrix(newSize);
    int **C11 = allocateMatrix(newSize), **C12 = allocateMatrix(newSize);
    int **C21 = allocateMatrix(newSize), **C22 = allocateMatrix(newSize);
    int **M1 = allocateMatrix(newSize), **M2 = allocateMatrix(newSize);
    int **M3 = allocateMatrix(newSize), **M4 = allocateMatrix(newSize);
    int **M5 = allocateMatrix(newSize), **M6 = allocateMatrix(newSize);
    int **M7 = allocateMatrix(newSize);
    int **temp1 = allocateMatrix(newSize), **temp2 = allocateMatrix(newSize);

    // Split matrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);

    // M2 = (A21 + A22)B11
    add(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);

    // M3 = A11(B12 - B22)
    subtract(B12, B22, temp1, newSize);
    strassen(A11, temp1, M3, newSize);

    // M4 = A22(B21 - B11)
    subtract(B21, B11, temp1, newSize);
    strassen(A22, temp1, M4, newSize);

    // M5 = (A11 + A12)B22
    add(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);

    // M6 = (A21 - A11)(B11 + B12)
    subtract(A21, A11, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);

    // M7 = (A12 - A22)(B21 + B22)
    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);

    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, temp1, newSize);
    subtract(temp1, M5, temp2, newSize);
    add(temp2, M7, C11, newSize);

    // C12 = M3 + M5
    add(M3, M5, C12, newSize);

    // C21 = M2 + M4
    add(M2, M4, C21, newSize);

    // C22 = M1 - M2 + M3 + M6
    subtract(M1, M2, temp1, newSize);
    add(temp1, M3, temp2, newSize);
    add(temp2, M6, C22, newSize);

    // Combine results into C
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Free all allocated memory
    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);
    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);
    freeMatrix(C11, newSize);
    freeMatrix(C12, newSize);
    freeMatrix(C21, newSize);
    freeMatrix(C22, newSize);
    freeMatrix(M1, newSize);
    freeMatrix(M2, newSize);
    freeMatrix(M3, newSize);
    freeMatrix(M4, newSize);
    freeMatrix(M5, newSize);
    freeMatrix(M6, newSize);
    freeMatrix(M7, newSize);
    freeMatrix(temp1, newSize);
    freeMatrix(temp2, newSize);
}

void printMatrix(int **M, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%4d ", M[i][j]);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter matrix size (must be a power of 2): ");
    scanf("%d", &n);

    // Allocate memory for matrices
    int **A = allocateMatrix(n);
    int **B = allocateMatrix(n);
    int **C = allocateMatrix(n); // Result matrix

    // Input A
    printf("Enter elements of matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Input B
    printf("Enter elements of matrix B (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Multiply using Strassen
    strassen(A, B, C, n);

    // Output Result
    printf("Result matrix C = A * B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    // Free memory
    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}
