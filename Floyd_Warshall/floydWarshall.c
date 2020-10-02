#include <stdio.h>
#include <stdlib.h>
#define INF 999999

typedef struct graph
{
    int v;
    int E;
    int **adj;
} graph;

int min(int a, int b)
{
    return ((a < b) ? a : b);
}

void getFloydWarshall(graph *g)
{
    int i, j, new;
    for (new = 0; new < g->v; new ++)
    {
        for (i = 0; i < g->v; i++)
        {
            for (j = 0; j < g->v; j++)
            {
                g->adj[i][j] = min(g->adj[i][j], (g->adj[i][new] + g->adj[new][j]));
            }
        }
    }

    printf("All pair sorted path Adj. matrix: \n");
    for (i = 0; i < g->v; i++)
    {
        for (j = 0; j < g->v; j++)
        {
            if (g->adj[i][j] == INF)
                printf("%5s ", "INF");
            else
                printf("%5d ", g->adj[i][j]);
        }
        printf("\n");
    }
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
            if (i == j)
                g->adj[i][j] = 0;
            else
                g->adj[i][j] = INF;
        }
    }

    i = 0;
    j = 0;
    printf("Enter the edges and crossponding weight\n");
    for (i = 0; i < g->E; i++)
    {
        int x, y, wt;
        scanf("%d %d %d", &x, &y, &wt);
        g->adj[x][y] = wt;
    }

    printf("Initial Adj. matrix: \n");
    for (i = 0; i < g->v; i++)
    {
        for (j = 0; j < g->v; j++)
        {
            if (g->adj[i][j] == INF)
                printf("%5s ", "INF");
            else
                printf("%5d ", g->adj[i][j]);
        }
        printf("\n");
    }

    getFloydWarshall(g);
    return 0;
}
/*
0 1 3
2 1 4
3 2 5
4 3 6
0 4 -4
0 2 8
3 0 2
1 4 7
1 3 1
*/