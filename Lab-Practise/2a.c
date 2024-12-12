#include <stdio.h>
int main()
{
    int m, n, p, q;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d%d", &m, &n);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d%d", &p, &q);
    if (n != p)
    {
        printf("The matrices cannot be multiplied.\n");
        return 0;
    }
    int firstMatrix[m][n], secondMatrix[p][q], result[m][q];
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &firstMatrix[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &secondMatrix[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}