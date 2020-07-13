//DFS(Depth First Search)

#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int V;
    int E;
    int **Adj;      //2D array
}graph;

void print_DFS(int** edges, int n, int sv, int* visited)
{
     int i;
     if(sv == 0)
        printf("A ");
     else if(sv == 1)
        printf("B ");
     else if(sv == 2)
        printf("C ");
     else if(sv == 3)
        printf("D ");
     else
        printf("E ");
     //printf("%d ", sv);
     visited[sv] = 1;
     for(i = 0;i<n;i++){
        if(i == sv)
             continue;
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
             print_DFS(edges, n, i, visited);
        }
     }
}

graph *adj_mat(){
    int i, u, v, sv;
    char ch;
    int* visited;
    graph *G = (graph *)malloc(sizeof(graph));
    printf("Enter the number of vertex and edge:\n");
    scanf("%d %d",&G->V,&G->E);
    G->Adj = (int **)malloc(sizeof(int) * (G->V ));
    if(!(G->Adj))
    {
        printf("memory error\n");
        return;
    }

    for(i = 0;i<G->V; i++)
        G->Adj[i] = (int *)malloc(sizeof(int) * (G->V));

    for(u = 0;u < G->V; u++)
    {
        for(v = 0;v < G->V; v++)
        {
            G->Adj[u][v] = 0;
        }
    }
    printf("Reading Edge: \n");
    for(i = 0; i < G->E ;i++){
        scanf("%d %d",&u,&v);
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
    visited = (int *)malloc(sizeof(int) * G->V);
    for(i = 0;i<G->V;i++)
    {
        visited[i] = 0;
    }
    printf("Enter the starting vertex:\n");
    scanf("%s", &ch);
    if (ch == 'A')
        sv = 0;
    print_DFS(G->Adj, G->V, sv, visited);
    printf("\n");
    return(G);


}


int main(){
    graph *g;
    int i,j;
    g = (graph *)malloc(sizeof(graph));
    g = adj_mat();
    printf("\n\n");
    printf("Crossponding Adj. Matrix:\n");
    for(i = 0;i<g->V;i++)
    {
        for(j = 0;j<g->V;j++)
        {
            printf("%d ",g->Adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
