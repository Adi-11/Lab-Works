#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int V;
    int E;
    //int m;
    int **Adj;      //2D array
    int *color;
}graph;

graph *adj_mat(){
    int i, u, v, sv;
    char ch;
    int* visited;
    graph *G = (graph *)malloc(sizeof(graph));

    printf("Enter the number of vertex and edge::\n");
    scanf("%d %d",&G->V,&G->E);

    G->Adj = (int **)malloc(sizeof(int) * (G->V ));

    if(!(G->Adj)){
        printf("memory error\n");
        return 0;
    }

    for(i = 0;i<G->V; i++)
        G->Adj[i] = (int *)malloc(sizeof(int) * (G->V));

    for(u = 0;u < G->V; u++){
        for(v = 0;v < G->V; v++){
            G->Adj[u][v] = 0;
        }
    }
    printf("Reading Edge:: \n");
    for(i = 0; i < G->E ;i++){
        scanf("%d %d",&u,&v);
        G->Adj[u -1][v - 1] = 1;
        G->Adj[v - 1][u - 1] = 1;
    }
    return(G);
}

int isSafeToColor(graph *G, int j, int v)
{
    int i;
    for(i = 0; i< G->V; i++){
        if(G->Adj[v][i] && G->color[i] == j)
            return 0;
    }
    return 1;
}

int graphColoring(graph *g, int start)
{
   int i;
   if(start == g->V)
    return 0;

   for(i = 1; i<= g->V; i++){
       if (isSafeToColor(g, i, start)){
           g->color[start] = i;
           if(graphColoring(g, start + 1) == 0)
                return 0;
       }
   }
}


int main(){
    graph *g;
    int i,j;

    g = (graph *)malloc(sizeof(graph));
    g = adj_mat();
    g->color = (int *)malloc(sizeof(int) * g->V);
    for(i = 0; i < g->V; i++)
        g->color[i] = 0;

    printf("\n\n");

    printf("Crossponding Adj. Matrix::\n");
    for(i = 0;i<g->V;i++){
        for(j = 0;j<g->V;j++){
            printf("%d ",g->Adj[i][j]);
        }
        printf("\n");
    }

    int start, max = 0;
    printf("Enetr the starting vertex:: ");
    scanf("%d",&start);
    graphColoring(g, start - 1);

    for(i = 0; i< g->V; i++){
        if(g->color[i] > max)
        max = g->color[i];
    }
    printf("\nMinimun chromatic no. is  %d\n\n",max);

    return 0;
}