#include <stdio.h>
void floyd(int arr[100][100], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((arr[i][k] + arr[k][j]) < arr[i][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    printf("The shortest distances between all pairs of vertices are:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > 100)
            {
                printf("%7s", "INF");
            }
            else
            {
                printf("%7d", arr[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int adj[100][100];
    printf("Enter the adjacency matrix of the graph (use 100 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    floyd(adj, n);
    return 0;
}