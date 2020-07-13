#include <stdio.h>
#include <stdlib.h>
#define err_code -999
#define max 20

typedef struct
{
    int edge;
    int vertex;
    int Adj[20][20];
}graph;

typedef struct queue
{
	int cap,*array,front,rear;
}queue;

void initialise(queue *q,int num)
{
	q->cap=num;
	q->front=-1;
	q->rear=-1;
	q->array=(int *)malloc(sizeof(int)*num);
}

int is_full(queue q)
{
	return((q.rear+1)%q.cap==q.front);
}

int is_empty(queue q)
{
	return(q.front==-1);
}

void Enqueue(queue *q,int data)
{
	if(is_full(*q))
	{
		printf("Queue is full\n");
		return;
	}
	q->rear=(q->rear+1)%q->cap;
	q->array[q->rear]=data;
	if(q->front==-1)
	{
		q->front=q->rear;
	}

}

int Dequeue(queue *q)
{
	if(is_empty(*q))
	{
		printf("Queue is empty\\n");
		return err_code;
	}
	int data;
	data=q->array[q->front];
	if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
		q->front=(q->front+1)%q->cap;
	return data;
}

int queue_size(queue q)
{
	int data;
	data=(q.cap-q.front+q.rear+1)%q.cap;
	if(data==0)
		return q.cap;
	return data;
}

void initialise_graph(graph *g,int V,int e)
{
    printf("\nReading edges:\n");
    int i,j;
    char s, u, p, v;
    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
            g->Adj[i][j]=0;
    }


    for(i=0;i<e;i++)
    {
		scanf("%c%c%c%c",&s,&u,&p,&v);
		//printf("u=%d and v=%d",u-96,v-96);
		g->Adj[u-96][v-96]=1;
		g->Adj[v-96][u-96] = 1;
    }
}

void bfs(graph *g,int s,int V)
{
    queue q;
    initialise(&q,max);
    Enqueue(&q,s);
    int visited[20]={0},i,j;
    printf("%c ",s + 96);
    visited[s]=1;
    while(!is_empty(q))
    {
        i=Dequeue(&q);
        for(j=1;j<=V;j++)
        {
            if(g->Adj[i][j]==1&&visited[j]==0)
            {
                printf("%c ",j + 96);
                Enqueue(&q,j);
                visited[j]=1;
            }
        }
    }
}

int main()
{
	int e,v;
	char ch;
	graph g;
	printf("enter the number of vertices and the edges of graph : ");
	scanf("%d %d",&v,&e);
	printf("**All the inputs must be in lower case**\n");
	initialise_graph(&g,v,e);
	printf("\n");
	printf("Enter the starting vertex:\n");
	fflush(stdin);
	scanf("%c",&ch);
	int t = ch - 96;
	bfs(&g,t,v);

}
