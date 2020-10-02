#include <stdio.h>
#include <stdlib.h>
#define INF 99999
typedef struct graph
{
    int v;
    int E;
    int **adj;
} graph;

int getMinVertex(int *distance, int *visisted, graph *g)
{
    int toReturn = -1, i;
    for (i = 0; i < g->v; i++)
    {
        if ((toReturn == -1 || distance[toReturn] > distance[i]) && !visisted[i])
        {
            toReturn = i;
        }
    }
    return toReturn;
}

void dijkstra(graph *g, int *visited)
{
    int *distnce = (int *)malloc(sizeof(int) * (g->v));
    int i, j;
    for (int i = 0; i < g->v; i++)
        distnce[i] = INF;

    distnce[0] = 0;

    for (i = 0; i < (g->v) - 1; i++)
    {
        int currentMinVertex = getMinVertex(distnce, visited, g);
        visited[currentMinVertex] = 1;
        for (j = 0; j < g->v; j++)
        {
            if (g->adj[currentMinVertex][j] && !visited[j])
            {
                int curDistance = distnce[currentMinVertex] + g->adj[currentMinVertex][j];
                if (curDistance < distnce[j])
                    distnce[j] = curDistance;
            }
        }
    }

    printf("The distances of each vertex form 0 is: \n");
    for (int i = 0; i < g->v; i++)
        printf("vertex: %d --> distance: %d\n", i, distnce[i]);
}

int main(int argc, char const *argv[])
{

    graph *g = (graph *)malloc(sizeof(graph));
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &g->v, &g->E);

    g->adj = (int **)malloc(sizeof(int *) * (g->v));

    int i, j;
    for (i = 0; i < g->v; i++)
    {
        g->adj[i] = (int *)malloc(sizeof(int) * (g->v));
    }

    i = 0;
    j = 0;
    for (i = 0; i < g->v; i++)
    {
        for (j = 0; j < g->v; j++)
        {
            g->adj[i][j] = 0;
        }
    }

    printf("Enter the edges and crossponding weight\n");
    i = 0;
    j = 0;
    for (i = 0; i < g->E; i++)
    {
        int x, y, wt;
        scanf("%d %d %d", &x, &y, &wt);
        g->adj[x][y] = wt;
        g->adj[y][x] = wt;
    }

    int *visited;
    visited = (int *)malloc(sizeof(int) * g->v);
    for (i = 0; i < g->v; i++)
        visited[i] = 0;
    dijkstra(g, visited);
    return 0;
}