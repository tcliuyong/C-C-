#include "DualLinkList.h"
linknode *initDualLinkList(int len)
{
	int i,j;
	linknode *head = (linknode *)malloc(sizeof(linknode));
	head = NULL; 
	linknode *prenode = (linknode *)malloc(sizeof(linknode));
	for(i = 0; i < len; i++)
	{
		
		linknode *current = (linknode *)malloc(sizeof(linknode));
		if(i == 0)
		{
			prenode->data = i;
			prenode->next = NULL;
			prenode->pre = NULL; 
		}
		else
		{
			current->data = i;
			current->pre = prenode;
			prenode->next = current;
			current->next = NULL;
			if(i == 1)
			head = prenode;
			prenode = prenode->next;	
		}
		
	}
	return head;
}
int getLinkLen(linknode *head)
{
	int len = 0;
	while(head)
	{
		len++;
		head = head->next;
		
	}
	return len;
}
linknode *addLinkNode(linknode *head,int loc,int data)
{
	linknode *node = (linknode *)malloc(sizeof(linknode));
	node = head;
	if(loc == 0)
	{
		exit(0);
	}
	while(loc--)
	{
		node = node->next;	
		if(node == NULL)
		exit(0);
	}
	linknode *addNode = (linknode *)malloc(sizeof(linknode));
	linknode *tmpNode = (linknode *)malloc(sizeof(linknode));
	tmpNode = node->next->next;
	addNode->data = data;
	addNode->next = node->next;
	node->next = addNode;
	tmpNode->pre = addNode;
	addNode->pre= node;
	return head;
}
linknode *removeLinkNode(linknode *head,int loc)
{
	linknode *node = (linknode *)malloc(sizeof(linknode));
	node = head;
	if(loc == 0)
	{
		exit(0);
	}
	while(loc--)
	{
		node = node->next;
		if(node == NULL)
		exit(0);	
	}
	linknode *preNode = (linknode *)malloc(sizeof(linknode));
	linknode *nextNode = (linknode *)malloc(sizeof(linknode));
	preNode = node->pre;
	nextNode = node->next; 
	preNode->next = node->next;
	nextNode->pre = node->pre;
	free(node);
	return head;
}
