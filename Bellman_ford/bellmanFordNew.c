#include <stdio.h>
#include <stdlib.h>
#define INF 999999

typedef struct graph
{
    int v;
    int E;
    int **adj;
} graph;

typedef struct pair
{
    int dist;
    int source;
} pair;

void getBellmenFord(graph *g, pair *makePair)
{

    int *distance = (int *)malloc(sizeof(int) * g->v);
    int i, j;
    for (i = 0; i < g->v; i++)
        distance[i] = INF;

    distance[0] = 0;
    int valid = (g->v) - 1;

    while (valid)
    {
        for (j = 0; j < g->E; j++)
        {
            int s = makePair[j].source;
            int d = makePair[j].dist;

            if (distance[s] != INF && distance[s] + g->adj[s][d] < distance[d])
            {
                distance[d] = distance[s] + g->adj[s][d];
            }
        }
        valid -= 1;
    }

    printf("Sorted Path form 0 to all the vertices is: \n");
    for (int i = 0; i < g->v; i++)
        printf("vertex: %d --> distance: %d\n", i, distance[i]);
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

    for (i = 0; i < g->v; i++)
    {
        for (j = 0; j < g->v; j++)
        {
            g->adj[i][j] = 0;
        }
    }

    i = 0;
    j = 0;

    pair makePair[g->E];

    printf("Enter the edges and crossponding weight\n");
    for (i = 0; i < g->E; i++)
    {
        int x, y, wt;
        scanf("%d %d %d", &x, &y, &wt);
        g->adj[x][y] = wt;
        makePair[i].source = x;
        makePair[i].dist = y;
    }

    getBellmenFord(g, makePair);
    return 0;
}