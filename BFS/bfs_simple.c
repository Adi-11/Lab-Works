#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct graph
{
    int v;
    int E;
    int **adj;
} graph;

typedef struct queue
{
    int cap;
    int *array;
    int front;
    int rear;
} queue;

void initialise(queue *q, int num)
{
    q->cap = num;
    q->front = -1;
    q->rear = -1;
    q->array = (int *)malloc(sizeof(int) * (q->cap));
}

int is_full(queue *q)
{
    return ((q->rear + 1) % q->cap == q->front);
}

int is_empty(queue *q)
{
    return (q->front == -1);
}

void Enqueue(queue *q, int data)
{
    if (is_full(q))
    {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->cap;
    q->array[q->rear] = data;
    if (q->front == -1)
    {
        q->front = q->rear;
    }
}

int Dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty\\n");
    }
    int data;
    data = q->array[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front = (q->front + 1) % q->cap;
    return data;
}

void runBFS(graph *g, int sv, int *visited)
{

    queue *q;
    q = (queue *)malloc(sizeof(queue));
    initialise(q, MAX);
    visited[sv] = 1;
    Enqueue(q, sv);
    printf("%d ", sv);
    while (!is_empty(q))
    {
        int top = Dequeue(q);
        int i;
        for (i = 0; i < g->v; i++)
        {
            if (visited[i])
                continue;
            if (g->adj[top][i] == 1)
            {
                printf("%d ", i);
                Enqueue(q, i);
                visited[i] = 1;
            }
        }
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
            g->adj[i][j] = 0;
        }
    }

    printf("Enter the edges: \n");
    for (i = 0; i < g->E; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g->adj[x][y] = 1;
        g->adj[y][x] = 1;
    }

    printf("Enter the starting vertex: \n");
    int sv;
    scanf("%d", &sv);

    int *visited;
    visited = (int *)malloc(sizeof(int) * g->v);
    for (i = 0; i < g->v; i++)
        visited[i] = 0;

    printf("The traversal is: \n");
    runBFS(g, sv, visited);
    return 0;
}