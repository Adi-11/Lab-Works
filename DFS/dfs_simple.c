#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int v;
    int E;
    int **adj;
} graph;

void runDFS(graph *g, int sv, int *visited)
{
    printf("%d ", sv);
    visited[sv] = 1;
    int i;
    for (i = 0; i < g->v; i++)
    {
        if (visited[i])
            continue;

        if ((!visited[i]) && g->adj[sv][i])
        {
            runDFS(g, i, visited);
        }
    }
}

int main(int argc, char const *argv[])
{
    graph *g = (graph *)malloc(sizeof(graph));
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &g->v, &g->E);

    g->adj = (int **)malloc(sizeof(int *) * (g->v));

    printf("this \n");
    int i, j;
    for (i = 0; i < g->v; i++)
    {
        g->adj[i] = (int *)malloc(sizeof(int) * (g->v));
    }
    printf("this \n");
    i = 0;
    j = 0;
    for (i = 0; i < g->v; i++)
    {
        for (j = 0; j < g->v; j++)
        {
            g->adj[i][j] = 0;
        }
    }
    printf("this \n");
    printf("Enter the edges: \n");
    i = 0;
    j = 0;
    for (i = 0; i < g->E; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g->adj[x][y] = 1;
        g->adj[y][x] = 1;
    }

    printf("Enter the starting vertex: \n");
    int sv;
    scanf("%d", &sv);
    int *visited;
    visited = (int *)malloc(sizeof(int) * g->v);
    for (i = 0; i < g->v; i++)
        visited[i] = 0;

    printf("The traversal is: \n");
    runDFS(g, sv, visited);

    return 0;
}