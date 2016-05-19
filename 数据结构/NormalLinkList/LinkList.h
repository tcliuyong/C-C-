#include<cstdlib>
#include<iostream>
using namespace std;
struct link
{
	int data;
	link *next;
};
class LinkList
{
	link *head; 
	public:
	LinkList(){head = NULL;}
	link* CreateTestLinkList(int n);
	void InsertLastLinkList(int data);
	link* GetHead();
	void InsertLocationLinkList(int location,int data);
	int GetLocLinkList(int loc);
	int GetValueLinkList(int value);
	void DelLinkList(int location);
	void ReverseLinkList();
};
