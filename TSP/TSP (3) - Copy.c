#include<stdio.h>
#define V 4

int travelling_sales_problem(int graph[][V],int visited[V])
{
    int i,j,ctr =0,cost=0,min,k;
    for (k=0;k<V-1;k++)
    {
        i=ctr;min=999;

        for(j=0;j<V;j++)
        {

            if((graph[i][j]<min)&& (visited[j]==0))
            {
                min=graph[i][j];
                ctr=j;
            }

        }
        visited[ctr]=1;
        cost=cost+min;
    }
    return (cost+graph[ctr][0]);
}
int main()
{
    int graph[][V] = { { 0, 10, 15, 20 },
                           { 10, 0, 35, 25 },
                           { 15, 35, 0, 30 },
                           { 20, 25, 30, 0 } };
    int visited[]={1,0,0,0};

    printf("Given graph in matrix form:\n");
    for (int i = 0; i <V; i++)
    {
        for (int j = 0; j <V; j++)
           printf("%d ", graph[i][j]);
    printf("\n");
    }
    printf("\n");


    int cost=travelling_sales_problem(graph,visited);

    printf("Minimum cost is %d\n ",cost);

    return 0;
}
