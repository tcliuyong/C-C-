#include "LinkList.h"
link* LinkList::CreateTestLinkList(int n)
{
	link *s,*tmp;
	s = (link *)new link;
	for(int i = 0 ;i < n ; i++)
	{
		tmp = (link *)new link;
		tmp -> data = i;
		tmp -> next = NULL;
		if(head == NULL)
		{
			head = tmp;
			s = head;
		}
		else
		{			
			s ->next = tmp;
			s = tmp;
		}
	}
	return head;
}
void LinkList::InsertLastLinkList(int data)
{
	link *tmp,*p;
	p = head;
	tmp = (link *) new link;
	tmp -> data = data;
	tmp -> next = NULL;
	if(head == NULL)
	{
		head = tmp;
		p = head;
	}
	else
	{
		while(p -> next != NULL)
		{
				p = p -> next;
		}
		p -> next =tmp;
		p = tmp;
		//cout<<p->data<<endl;
	}
}
void LinkList::InsertLocationLinkList(int loc,int data)
{
	link *tmp,*p;
	tmp = (link *)new link;
	p = head;
	while(p->next != NULL && loc != 0)
	{
		loc --;
		p = p->next;;
	}
	tmp->data = data;
	tmp->next = p->next;  
	p ->next = tmp;
}
void LinkList::DelLinkList(int loc)
{
	link *s,*p;
	p = (link *)new link;
	s = (link *) new link;
	p = head;
	while(p->next != NULL && loc != 0)
	{
		loc --;
		s = p;
		p = p->next;
	}
	s ->next = p->next;
	delete p;
}
int LinkList::GetLocLinkList(int loc)
{
		link *p = (link *)new link;
		p = head;
		while(p -> next != NULL && loc != 0)
		{
			loc --;
			p = p ->next;
		}
		return p->data;
}
int LinkList::GetValueLinkList(int value)
{
		link *p;
		p = (link *)new link;
		p = head;
		int loc = 0;
		while(p -> next != NULL)
		{
			loc ++;
			p = p->next;
			if(p->data == value)
			{
				return loc;
			}
		}

}
void LinkList::ReverseLinkList()
{
	link *p = head, *q = 0;//first是链表的头节点
	 while(p){
	  link *r = q;
	  q = p;
	  p = p->next;
	  q->next = r;
	 }
	 head = q;
}
link* LinkList::GetHead()
{
	return head;
}
