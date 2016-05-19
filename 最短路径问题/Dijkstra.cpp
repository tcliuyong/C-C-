/*
普通寻找最短路径算法 
*/
#include<iostream>
#include <stdlib.h>
#include<stdint.h>
using namespace std;
void Dijkstra(int n,int v,int dist[],int prev[],int **cost)
{
	int i,j,maxint = 65535,*s,temp,u;
	s = (int *)malloc(sizeof(int) *n);
	for(i = 1; i <= n; i++)
	{
		dist[i] = cost[v][i];
		s[i] = 0;
		if(dist[i] == maxint)
		{
			prev[i] = 0;
		}
		else
		{
			prev[i] = v;
		}
	}
	dist[v] = 0;
	s[v] = 1;
	for(i = 1; i < n; i++)
	{
		temp = maxint; u =v;
		for(j = 1; j <= n; j++)
		{
			if((!s[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];	
			}
		}
		s[u] = 1;
		for(j=1; j <=1; j++)
		{
			if((!s[j]) && (cost[u][j]) < maxint)
			{
				int newdist = dist[u] + cost[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				} 
			}
		}
	}
}
void showPath(int n, int v, int u,int *dist,int *prev)
{
	int j = 0,w = u,count = 0,*way;
	way = (int *)malloc(sizeof(int) * (n+1));
	while(w != v)
	{
		count++;
		way[count] = prev[w];
		w = prev[w];		
	}
	printf("best path is:");
	for(j = count; j >= 1;j--)
	{
		printf("%d -> ",way[j]);
	}
	printf("%d\n",u);
}

int main()
{
	int i,j,t,n,v,**cost,*dist,*prev;
	printf("please input the node:\n");
	scanf("%d",&n);
	printf("please input the cost status:\n");
	cost = (int **)malloc(sizeof(int) * (n+1));
	for(i = 1; i <= n;i++)
	{
		cost[i] = (int * )malloc(sizeof(int) * (n+1));
	}	
	for(j=1; j <= n; j++)
	{
		for(t=1; t <= n; t++)
		{
			scanf("%d",&cost[j][t]);
		}
	}
	dist = (int *)malloc(sizeof(int) * n);
	prev = (int *)malloc(sizeof(int) * n);
	printf("please input the source node:");
	scanf("%d",&v);
	Dijkstra(n,v,dist,prev,cost);
	printf("*************************\n");
	printf("have confrim the best path\n");
	printf("***********************");
	for(i = 1; i <= n; i++)
	{
		if(i != v)
		{
			printf("the distance cost from node %d to node %d is %d\n",v,i,dist[i]);
			printf("the pre - node of node %d is node %d\n",i,prev[i]);
			showPath(n,v,i,dist,prev);
		}
	}
} 