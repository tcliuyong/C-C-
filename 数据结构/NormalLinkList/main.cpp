#include "LinkList.h"
int main()
{
	LinkList l;
	link *list,*p;
	list = l.CreateTestLinkList(10);
	l.InsertLastLinkList(100);
	l.InsertLocationLinkList(2,1000);
	l.DelLinkList(2);
	p = l.GetHead();
	while(p -> next != NULL)
	{
		cout<<p->data<<endl;
		p = p -> next;
	}
	cout<<p->data<<endl;
	int loc = l.GetLocLinkList(0);
	cout<<loc<<endl;
	int value = l.GetValueLinkList(9);
	cout<<value<<endl;
	l.ReverseLinkList();
		while(p -> next != NULL)
	{
		cout<<p->data<<endl;
		p = p -> next;
	}
	cout<<p->data<<endl;
	return 0;
}
