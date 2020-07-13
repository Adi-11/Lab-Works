#include<stdio.h>
#include<stdlib.h>
#define INF 99999
#define max 100

typedef struct Floyd_warshall{
    int V;
    int E;
    int Adj[max][max];
}graph;

void initialise_graph(graph *g)
{
    int i,j,u,v,w;
    for(i=1;i<=g->V;i++)
    {
        for(j=1;j<=g->V;j++)
        {
            if(i==j)
                g->Adj[i][j]=0;
            else
                g->Adj[i][j]=INF;
        }
    }
    printf("Enter the edges of the graph and their weight:\n");
    for(i=1;i<=g->E;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        g->Adj[u][v]=w;
    }

    printf("The initial matrix is:\n");
    for(i=1;i<=g->V;i++)
    {
        for(j=1;j<=g->V;j++)
        {
            //printf("%d ",g->Adj[i][j]);
            if(g->Adj[i][j] == 99999)
            {
                g->Adj[i][j] = "INF";
                printf("INF   ");
            }
            else
            printf("%d   ",g->Adj[i][j]);


        }
        printf("\n");
    }
    printf("\n");
}

int min(int x, int y)
{
    if(x < y)
    return x;
    else
    return y;
}

void floyd_warshall(graph g)
{
    int i,j,k;
    for(k=1;k<=g.V;k++)
    {
        for(i=1;i<=g.V;i++)
        {
            for(j=1;j<=g.V;j++)
                g.Adj[i][j]=min(g.Adj[i][j],g.Adj[i][k]+g.Adj[k][j]);
        }
    }

    printf("All shortest pair path is:\n");
    for(i=1;i<=g.V;i++)
    {
        for(j=1;j<=g.V;j++)
            printf("%d ",g.Adj[i][j]);
        printf("\n");
    }
}


int main()
{
    graph G;
    int i,j;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d",&G.V,&G.E);
    initialise_graph(&G);
    floyd_warshall(G);
    return 0;
}
