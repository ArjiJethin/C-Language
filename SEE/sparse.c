#include <stdio.h>
int main()
{
    int sparse[6][6] = {{0, 0, 1, 0, 2, 0},
                        {0, 3, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 4},
                        {0, 0, 5, 0, 0, 0},
                        {0, 0, 0, 6, 0, 0},
                        {0, 0, 0, 0, 7, 0}};
    int size = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (sparse[i][j] != 0)
            {
                size++;
            }
        }
    }

    int matrix[3][size];
    int k = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (sparse[i][j] != 0)
            {
                matrix[0][k] = sparse[i][j];
                matrix[1][k] = i;
                matrix[2][k] = j;
                k++;
            }
        }
    }
    printf("%-8s %-8s %-8s", "Value", "Row", "Column");
    for (int i = 0; i < size; i++)
    {
        printf("\n%-8d %-8d %-8d", matrix[0][i], matrix[1][i] + 1, matrix[2][i] + 1);
    }
}