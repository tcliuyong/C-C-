#include <stdio.h>
#include <stdlib.h>
typedef struct linknode
{
	int data;
 	struct linknode *next;
 	struct linknode *pre;
}linknode ;
linknode *initDualLinkList(int len);
int getLinkLen(linknode *head);
linknode *addLinkNode(linknode *head,int loc,int data);
linknode *removeLinkNode(linknode *head,int loc);
