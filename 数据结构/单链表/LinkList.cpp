#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct LinkList
{
	int value;
	LinkList *next;	
};
LinkList *head=(LinkList *)malloc(sizeof(LinkList));
void CreateList()
{
	char ch;
	LinkList *s;
	LinkList *temp = head;
	temp->next=NULL;
	ch=getchar();
	while(ch!='#')
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->value=ch;
		temp->next=s;
		s->next=NULL;
		temp=s;
		ch=getchar();
	}
}
void ShowList()
{
	LinkList *temp;
	temp=head->next;
	while(temp!=NULL)
	{
		printf("%c",temp->value);
		temp=temp->next;
	}
	cout<<endl;
}
LinkList *GetData(LinkList *head,int i)
{
	int j;
	LinkList *p;
	p=head->next;
	j=1;
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;
		j++;
	}
	if(i==j)
	return p;
	else 
	return NULL;	
}
void ListInsert(LinkList *head,int i,int e)
{
	int j;
	LinkList *p,*s;
	p=head;
	j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i-1)
	return ;
	s=(LinkList *)malloc(sizeof(LinkList));
	s->value=e;
	s->next=p->next;
	p->next=s;
}
void ListDelete(LinkList *head,int i)
{
	LinkList *p,*q;
	int j=0;
	p=head;
	while(p->next&&(j<i-1))
	{
		p=p->next;
		++j;
	}
	if(!p || j>i-1)
	return ;
	q=p->next;
	p->next=q->next;
	free(q);
} 
int main() 
{
	printf("输入要建立链表的数据(以'#'结尾):\n");
	CreateList();
	ShowList();
	int n;
	printf("输入要要查找第几个数据\n");
	scanf("%d",&n);
	LinkList *y=(LinkList *)malloc(sizeof(LinkList));
	y=GetData(head,n);
	if(y!=NULL)
	printf("%c\n",y->value);
	
	int a;
	char b;
	printf("请输入要插入的位子和数据:\n");
	cin>>a>>b;
	ListInsert(head,a,b);
	ShowList();
	int m;
	printf("请输入要删除的位子:\n");
	cin>>m;
	printf("删除操作：\n");
	ListDelete(head,m);
	ShowList();
	return 0;
}