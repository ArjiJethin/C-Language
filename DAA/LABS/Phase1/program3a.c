#include <stdio.h>
#include <stdbool.h>

void initializeGraph(int adj[100][100], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int adj[100][100], int start, int edge)
{
    adj[start][edge] = 1;
    adj[edge][start] = 1;
}

void DFS(int adj[100][100], int vertices, int vertex, bool visited[])
{
    visited[vertex] = true;
    for (int i = 0; i < vertices; i++)
    {
        if (adj[vertex][i] && !visited[i])
        {
            DFS(adj, vertices, i, visited);
        }
    }
}

bool isConnected(int adj[100][100], int vertices)
{
    bool visited[100] = {false};
    DFS(adj, vertices, 0, visited);
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int adj[100][100];
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(adj, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(adj, start, end);
    }

    bool connected = isConnected(adj, vertices);
    if (connected)
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }
}