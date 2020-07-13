#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int V;
    int E;
    int m;
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
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
    return(G);
}

int checkForValidation(graph *g)
{
    int i,j;
    for(i = 0; i < g->V; i++){
        for(j = i + 1; j < g->V; j++){
            if(g->Adj[i][j] == 1 && g->color[j] == g->color[i])
                return 0;
        }
    }
    return 1;
}

int graphColoring(graph *g, int start)
{
    if(start == g->V){
        if(checkForValidation(g)){
            int i;
            printf("Solution for the given graph is::\n");
            for(i = 0; i < g->V; i++){
                printf("Vertex::%d --> ",i + 1);
                printf("%d",g->color[i]);
                printf("\n");
            }
            return 1;
        }
        return 0;
    }
    int i;
    for(i = 1; i <= g->m; i++){
        g->color[start] = i;
        if(graphColoring(g, start + 1)){
            return 1;
        }
        g->color[start] = 0;
    }
    return 0;
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

    printf("Enter the number of color:: ");
    scanf("%d",&g->m);

    int start;
    printf("Enetr the starting vertex:: ");
    scanf("%d",&start);
    graphColoring(g, start - 1);
    return 0;
}