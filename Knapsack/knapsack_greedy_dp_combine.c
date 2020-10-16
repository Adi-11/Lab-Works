#include<stdio.h>
#include<stdlib.h>

typedef struct knapsack{
	int v, w;
}knap;
int findpos(int capw,int m[][capw+1],int n,int pt)
{
	int i,j;
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=capw;j++)
		{
			if(m[i][j]==pt)
				return(i);
		}
	}
    return -1;	
}
void knapsack_dp(knap *k,int n,int capw)
{
	int m[n+1][capw+1],i,j,index[n],pt,pos=0,profit=0,s1,s2,weights=0;
	knap temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(k[j].v>k[j+1].v)
			{
				temp=k[j];
				k[j]=k[j+1];
				k[j+1]=temp;
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=capw;j++)
		{
			if(i==0||j==0)
				m[i][j]=0;
			else
			{
				s1=m[i-1][j];
				if((j-k[i-1].w)>=0)
				{
					s2=m[i-1][j-k[i-1].w]+k[i-1].v;
				}
				else{
					s2=0;
				}
				if(s1>s2)
					m[i][j]=s1;
				else
					m[i][j]=s2;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		index[i]=0;
	}
	i=0;
	profit=m[n][capw];
	pt=m[n][capw];
	while(pos!=-1&&pt!=0)
	{
		pos=findpos(capw,m,n,pt);
		if(pos>0)
		{
			index[pos-1]=1;
		}
		pt=profit-k[pos-1].v;
	}
	
	for(i=0;i<n;i++)
	{
		if(index[i]==1)
			weights+=k[i].w;
	}
	
	printf("\n\n the optimal solutions according to dynamic programming method in knapsack are:-");
	printf("\n the weights included in the container is %d",weights);
	printf("\n the profit gained is %d",profit);
}
void knapsack_greedy(knap* k, int n, int capw)
{
	int i,j,temp,top=0,num=0;
	knap temp1;
	float x[n],tempf,capf=0,profitf=0,cap=0;
	for(i=0;i<n;i++)
		x[i]=((float)k[i].v/k[i].w);
		
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
			if(x[j]<x[j+1])
			{
				tempf=x[j];
				x[j]=x[j+1];
				x[j+1]=tempf;
				temp1=k[j];
				k[j] = k[j+1];
				k[j+1]=temp1;
			}
	}

	while(capf<capw&&top<n)
	{
		if((capf+k[top].w)<=capw)
		{
			num++;
			capf=capf+k[top].w;
			profitf+=k[top].v;
			
		}
		else
		{
			num++;
			cap=capf;
			capf=capf+(((float)(capw-capf))/k[top].w)*k[top].w;
			profitf=profitf+(((float)(capw-cap))/k[top].w)*k[top].v;
			
		}
		top++;
	}
	printf("\n\n the optimal solutions according to greedy method in knapsack are:-");
	printf("\n the weights included in the container is %.2f",capf);
	printf("\n the profit gained is %.2f",profitf);
	
}
int main()
{
	int capw,n,i;
	printf("Enter the no. of elements present, capacity of container in weight:\n");
	scanf("%d%d",&n,&capw);
	knap *k = (knap*)malloc(sizeof(knap)*n);
	
	printf("Enter the weights: \n");
	for(i=0;i<n;i++)
		scanf("%d",&k[i].w);
	printf("Enter the values: \n");
	for(i=0;i<n;i++)
		scanf("%d",&k[i].v);
	knapsack_greedy(k, n, capw);
	knapsack_dp(k ,n, capw);
}