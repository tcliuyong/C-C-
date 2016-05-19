/*
�и�ȨѰ�����·���㷨 
*/
#include<iostream>
#include <stdlib.h>
#include<stdint.h>
#define maxnum 100
#define maxint 999999
using namespace std;
struct Edge
{
int u , v;
int weight;	
};
int dist[maxnum];
int nodenum,edgenum,source;
struct Edge edge[maxnum];
void init()
{
	int i;
	printf("������� ���� Դ��");
	cin>>nodenum>>edgenum>>source;
	for(i = 1; i <= nodenum; ++i)
	{
		dist[i] = maxint;
	}
	dist[source] = 0;
	for(i = 1; i <= edgenum; ++i)
	{
		printf("����%d�ߵ�����յ��Ȩֵ");
		cin>>edge[i].u>>edge[i].v>>edge[i].weight;
		if(edge[i].u == source)
			dist[edge[i].v] = edge[i].weight;
	}
}
//�ɳڼ��� 
void relax(int u, int v, int weight)
{
	if(dist[v] > dist[u] + weight)
	dist[v] = dist[u] + weight; 
}
int Bellman_Ford()
{
	int flag = 1,i,j;
	for(i = 1; i <= nodenum -1; ++i)
	{
		for(j = 1; j <= edgenum; ++j)
		{
			relax(edge[j].u,edge[j].v,edge[j].weight); 
		}
	}
	//�жϸ���
	for(i = 1; i <= edgenum; ++i)
	{
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].weight)
		{
			flag = 0;
			break;
		}
	}
	return flag; 
}

int main()
{
	int i;
	init();
	if(Bellman_Ford())
	{
		for(i = 1; i <= nodenum; i++)
		{
			cout<<dist[i];
		}
		cout<<endl;
	}
} 