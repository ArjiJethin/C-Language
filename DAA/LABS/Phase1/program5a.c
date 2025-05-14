#include <stdio.h>
void warshall(int arr[100][100], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = 1;
            }
        }
    }
    printf("\nThe transitive closure of the given graph is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
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
    printf("Enter the adjacency matrix of the graph (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    warshall(adj, n);
    return 0;
}