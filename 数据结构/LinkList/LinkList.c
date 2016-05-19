#include  "LinkList.h"
linknode *init(linknode *head,int k)
{
	int i = 0;
	
	linknode *h = (linknode *)malloc(sizeof(linknode));

	for(i = 0;i <= k; i++)
	{
		linknode *tmp = (linknode *)malloc(sizeof(linknode));
		tmp ->data = i;
		
		tmp ->next = NULL;
	
		if(i == 0)
		{
			head = tmp;
			
			h = head;	
		}
		else
		{
			head ->next = tmp;
			head = head->next;	
		}
	}
	return h;
}
int LenLink(linknode *head)
{
	int count = 0;
		while(head->next != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}
linknode *FindKthToTail(linknode *head, int k)
{
	int i;
	linknode *start = (linknode *)malloc(sizeof(linknode));
	linknode *end = (linknode *)malloc(sizeof(linknode));
	linknode *tmp = (linknode *)malloc(sizeof(linknode));
	start = head;
	end = start;
	if(k == 0 || k > LenLink(head))
	{
		printf("make fun?\n");
		exit(0);
	}
	for(i = 0; i < k; i++)
	{
		end = end -> next;		
	}
	while(end -> next != NULL)
	{
		start = start -> next;
		end = end -> next;
	}
	return start;
}
void *AddLinkNode(linknode *head,int data,int loc)
{
	linknode *tmp = (linknode *)malloc(sizeof(linknode));
	linknode *t = (linknode *)malloc(sizeof(linknode));
	linknode *node = (linknode *)malloc(sizeof(linknode));
	tmp = head;
	while(loc--)
	{
		tmp = tmp->next;
	}
	
	node->data = data;
	node->next = tmp->next;
	tmp->next = node;
}
void *RemoveLinkNode(linknode *head,int loc)
{
	linknode *tmp = (linknode *)malloc(sizeof(linknode));
	linknode *t = (linknode *)malloc(sizeof(linknode));
	linknode *node = (linknode *)malloc(sizeof(linknode));
	tmp = head;
	while(loc--)
	{
		tmp = tmp->next;
	}
	t = tmp->next;
	tmp->next = t->next;
	delete t; 
}
void *ORemoveLinkNode(linknode *node)
{
	if(node->next != NULL)
	{
			linknode *tmp = (linknode *)malloc(sizeof(linknode));
	tmp= node->next;
	node->data = tmp->data;
	node->next = tmp->next;
	delete tmp;
	}
	else
	{
		node = NULL;
	}

	
}

linknode *ReverseLink(linknode *head)
{
	linknode *pReverseHead = (linknode *)malloc(sizeof(linknode));
	linknode *pNode = (linknode *)malloc(sizeof(linknode));
	linknode *pPre = (linknode *)malloc(sizeof(linknode));
	pReverseHead = NULL;
	pNode = head;
	pPre = NULL;
	while(pNode != NULL)
	{
		linknode *pNext = (linknode *)malloc(sizeof(linknode));
		pNext = pNode->next;
		if(pNext == NULL)
			pReverseHead = pNode;
		pNode->next = pPre;
		pPre = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}
