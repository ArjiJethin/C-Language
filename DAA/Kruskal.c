#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph
{
    int V, E;
    struct Edge *edge;
};

// Structure to represent a subset for union-find
struct Subset
{
    int parent;
    int rank;
};

// Function to create a graph
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

// Find set of an element i (uses path compression)
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        // Path compression: directly assign parent to the root
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union of two sets (uses union by rank)
void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort
int compareEdges(const void *a, const void *b)
{
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->weight - e2->weight;
}

// Kruskal's algorithm
void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V]; // Store result MST
    int e = 0;             // Index for result[]
    int i = 0;             // Index for sorted edges

    // Step 1: Sort all edges in non-decreasing order of weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for creating subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize the subsets (each vertex is its own parent)
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Number of edges in MST = V - 1
    while (e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edge[i++];

        // Find the root of the source and destination vertices
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, include it in the result
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the resulting MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
}

// Main function
int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph *graph = createGraph(V, E);

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph->edge[i].src = u - 1;
        graph->edge[i].dest = v - 1;
        graph->edge[i].weight = w;
    }

    KruskalMST(graph);

    return 0;
}
