#include <stdio.h> 
#include <stdlib.h>
#define INF 999999


int minKey(int key[], int mstSet[], int V) { 
    int min = INF, min_index, v;
    for (v = 0; v < V; v++) 
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index; 
} 


int printMSTree(int parent[], int **graph, int V) {
    int cost = 0, i;
    printf("Edge \tWeight\n"); 
    for (i = 1; i < V; i++) {
        printf("%d %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        cost += graph[i][parent[i]];
    }
    printf("Cost: %d.\n", cost);
} 


void primMST(int **graph, int V) { 
    int parent[V]; 
    int key[V]; 
    int mstSet[V]; 
    int i, count, u, v;
    for (i = 0; i < V; i++) 
        key[i] = INF, mstSet[i] = 0; 
  
    key[0] = 0; 
    parent[0] = -1;
    for (count = 0; count < V - 1; count++) { 
        u = minKey(key, mstSet,V); 
        mstSet[u] = 1; 
        for (v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    }
    printMSTree(parent, graph, V); 
} 

int setAdgecencyMatrix(int** adj, int edges, int vertices){
    int i, j, x , y, w;
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &x, &y, &w);
        adj[x-1][y-1] = w;
        adj[y-1][x-1] = w;
    }
    return 0;
}

int printAdjacencyMatrix(int **adj, int V){
    int i, j;
    printf("Adjacency Matrix:\n");
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            if(adj[i][j]==INF)
                printf("INF ");
            else
                printf("%3d ", adj[i][j]);
        }
        printf("\n");
    }
}
  
int main() 
{ 
    int **adj,i,j,v ,e, bi;
    printf("Number of vertices: ");
    scanf("%d",&v);
    adj = (int **)malloc(sizeof(int*)*v);
    for(i = 0; i < v; i++){
        adj[i] = (int *)malloc(sizeof(int)*v);
        for(j = 0; j < v; j++){
            if(i==j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }
    printf("Number of edges: ");
    scanf("%d",&e);
    printf("Enter 2 vertices and correspoding weight for each edge:\n");
    setAdgecencyMatrix(adj, e ,v);
    printAdjacencyMatrix(adj, v);
    primMST(adj, v); 
    return 0; 
} 

