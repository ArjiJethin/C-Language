#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = data;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void BFS(int graph[MAX][MAX], int vertices, int start, int visited[])
{
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty())
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int vertices, graph[MAX][MAX], visited[MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    int start;
    scanf("%d", &start);

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    printf("Breadth First Search (BFS) traversal from vertex %d:\n", start);
    BFS(graph, vertices, start, visited);

    return 0;
}