#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct LinkList
{
	int data;
	LinkList *next;	
};
class Link
{
	private:
	LinkList L;
	LinkList *head;
	int len;
	public:
	void init();
	void showList();
	void addData(int data);
	int getData(int pos);
	void delData(int pos);
	void insertData(int data, int pos);
	void converlist();
};
void Link::init()
{
	len = 0;

	head = NULL;	
}
void Link::addData(int d)
{
	LinkList *t;
	LinkList *temp = new LinkList;
	if(head == NULL)
	{
		head = new LinkList;
		head->data = d;
		head->next = NULL;
		t = new LinkList;
		t = head;
	}
	
	else if(t != NULL)
	{
		temp->data = d;
		temp->next = NULL;
		t->next = temp;
		t = temp;
	}
		len++;
	
}
void Link::showList()
{
	LinkList *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	cout<<endl;
}
void Link::delData(int pos)
{
	int i = 0;
	LinkList *temp;
	temp=head;
	LinkList *p = new LinkList;
	while(temp != NULL)
	{
	
		if(i == pos - 1)
		{
		
			p = temp;	
		}	
		else if(i == pos)
		{
			p->next = temp->next;
			free (temp);
			break;
		}
		i++;
		temp = temp->next;
	}
}
void Link::insertData(int data, int pos)
{
	int i = 0;
	LinkList * temp = new LinkList;
	temp = head;
	LinkList *p = new LinkList;
	LinkList *Inse = new LinkList;
	Inse->data = data;
	Inse->next = NULL;
	while((temp != NULL) && (temp->next != NULL))
	{
		if(i == pos - 1)
		{
			p = temp;	
		}	
		else if(i == pos)
		{
			p->next = Inse;
			Inse->next = temp;
		}
		i++;
		temp = temp->next;
	}
}
int Link::getData(int pos)
{
	int i = 0;
	LinkList *temp = new LinkList;
	temp = head;
	while(temp != NULL && temp->next != NULL)
	{
		if(pos == i)
		{
			return temp->data;
			
		}
		temp = temp->next;
		i++;
	}
	return -1;
	
}
void Link::converlist()
{
if( (NULL==head)||(NULL==head->next) )return ;  //边界检测  
    LinkList* pPre=head;    //先前指针  
    LinkList* pCur=pPre->next;  //当前指针  
    LinkList* pNext=NULL;       //后继指针  
    while(pCur!=NULL)  
    {  
        pNext=pCur->next;  
        pCur->next=pPre;  
        pPre=pCur;  
        pCur=pNext;  
    }  
    head->next=NULL;  
    head=pPre;        //记录下新的头结点  
}