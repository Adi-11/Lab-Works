#include<stdio.h>
#include<stdlib.h>

typedef struct MST{
    int source;
    int dest;
    int weight;
}tree;

void bsort(tree *edge, int E)
{
    int i, j;
    tree temp;
    
    for (i = 0; i < E - 1; i++)
    {
        for (j = 0; j < (E - 1 - i); j++)
        {
            if (edge[j].weight > edge[j + 1].weight)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            } 
        }
    }

}

int find_parent(int n, int *parent)
{
    if(parent[n] == n){
        return n;
    }

    return find_parent(parent[n], parent);
}



void Kruskals(tree *E, int edge, int vertex)
{
    //sort the array according to weight
    bsort(E, edge);
    tree output_edge[vertex - 1];
    //printf("2\n");
    int parent[vertex], i;
    for(i = 0; i < vertex; i++){
        parent[i] = i;
    }

    int ctr = 0, j = 0;
    tree cur_edge;
    while (ctr != vertex - 1){
        cur_edge = E[j];
        //check if to add current edge in the output array is safe or not
        int source_parent = find_parent(cur_edge.source, parent);
        int dest_parent = find_parent(cur_edge.dest, parent); 

        if(source_parent != dest_parent){
            output_edge[ctr] = cur_edge;
            ctr++; 
            parent[source_parent] = dest_parent; 
        }
        j++;
    }

    printf("\n");

    printf("The final array for the MST is:\n");
        for(i = 0; i < vertex-1; i++){
            if(output_edge[i].source < output_edge[i].dest){
                printf("%d-->%d : %d", output_edge[i].source, output_edge[i].dest, output_edge[i].weight);
                printf("\n");
            }
            else
            {
                printf("%d-->%d : %d", output_edge[i].dest, output_edge[i].source, output_edge[i].weight);
                printf("\n");
            }      
        }
    int sum = 0;
    printf("The total cost is: ");
    for(i = 0; i < vertex - 1 ; i++){
        sum = sum + output_edge[i].weight;
    }
    printf("%d", sum);
}


int main()
{
    int E, V;
    printf("Enter the Number of Vertices and Edges:\n");
    scanf("%d %d", &V, &E);
    tree Edge[E]; 
    int i, s, d, w; 
    printf("Enter the Source Vertix, Destination Vertex and Weight:\n"); 
    for(i = 0; i< E; i++){
        // printf("%d\n", i);
        scanf("%d%d%d", &s, &d, &w);
        Edge[i].source = s;
        Edge[i].dest = d;
        Edge[i].weight = w;  
    }
    //printf("1\n");
    Kruskals(Edge, E, V);
    return 0;
}