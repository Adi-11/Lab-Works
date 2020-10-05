//Tutorial link: https://www.youtube.com/watch?v=JE0JE8ce1V0

#include <stdio.h>
#include <stdlib.h>
#define VISITED(n) (1 << n) - 1
#define INF 999999

int dp[100001][100001];

typedef struct graph
{
    int v;
    int E;
    int **adj;
} graph;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int TSP(graph *g, int mask, int pos)
{
    if (mask == VISITED(g->v))
        return g->adj[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    int curCity;
    for (curCity = 0; curCity < g->v; curCity++)
    {
        if ((mask & (1 << curCity)) == 0)
        {
            int curCost = g->adj[pos][curCity] + TSP(g, (mask | (1 << curCity)), curCity);
            // printf("%d\n", curCost);
            ans = min(ans, curCost);
        }
    }

    dp[mask][pos] = ans;
    return dp[mask][pos];
}

/*
4 6

0 1 10
0 2 15
0 3 20
1 3 25
2 3 30
1 2 35
*/
int callTSP(graph *g)
{
    int mask = 1;
    int pos = 0;
    return TSP(g, mask, 0);
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

    // int i, j;
    for (i = 0; i < (1 << (g->v)); i++)
    {
        for (j = 0; j < g->v; j++)
        {
            dp[i][j] = -1;
        }
    }

    int result = callTSP(g);
    printf("The minumum cost for travelling each of the city is: %d\n", result);
    return 0;
}