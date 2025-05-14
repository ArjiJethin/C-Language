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

void addEdge(int adj[100][100], int start, int end)
{
    adj[start][end] = 1;
    adj[end][start] = 1;
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
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int adj[100][100];
    initializeGraph(adj, vertices);

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(adj, start, end);
    }

    if (isConnected(adj, vertices))
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }
}