#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct linknode
{
	int data;
	linknode *next;
};
linknode *init(linknode *head,int k);
int LenLink(linknode *head);
linknode *FindKthToTail(linknode *head, int k);
void *AddLinkNode(linknode *head,int data,int loc);
void *RemoveLinkNode(linknode *head,int loc);
void *ORemoveLinkNode(linknode *node);
linknode *ReverseLink(linknode *head);
