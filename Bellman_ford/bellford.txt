#include <stdio.h>
#include <stdlib.h>
#define max 20
#define infinity 9999

typedef struct
{
    int e,v,array[max][max];
}graph;

void initialise(graph *g)
{
    int i,j,x,y,w;
    for(i=1;i<=g->v;i++)
    {
        for(j=1;j<=g->v;j++)
            g->array[i][j]=0;
    }
    printf("Enter the edges of the graph and their weight : ");
    for(i=1;i<=g->e;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        g->array[x][y]=w;
    }
}

int value(graph g,int visited[],int D[])
{
    int i;
    for(i=1;i<=g.v;i++)
    {
        if(D[i]!=infinity && visited[i]==0)
            return i;
    }
}

void bellman_ford(graph g,int u)
{
    int D[g.v+1],i,j,k,index;
    for(i=0;i<=g.v;i++)
        D[i]=infinity;
    for(k=1;k<g.v;k++)
    {
       D[u]=0;
       int visited[g.v+1];
       for(i=1;i<=g.v;i++)
        visited[i]=0;
       for(i=1;i<=g.v;i++)
       {
           index=value(g,visited,D);
           visited[index]=1;
           for(j=1;j<=g.v;j++)
           {
               if(g.array[i][j]!=0)
               {
                   if(D[j]>D[index]+g.array[index][j])
                    D[j]=D[index]+g.array[index][j];
               }
           }
       }
    }

    for(i=1;i<=g.v;i++)
        printf("vertex = %d,, Distance = %d \n",i,D[i]);
}

int main()
{
    int u;
    graph g;
    printf("Enter the no. of vertex and edge of graph : ");
    scanf("%d %d",&g.v,&g.e);
    initialise(&g);
    printf("Enter the starting vertex : ");
    scanf("%d",&u);
    bellman_ford(g,u);
    return 0;
}
