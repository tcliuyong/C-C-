#include  "LinkList.h"
int main()
{
	linknode *h= (linknode *)malloc(sizeof(linknode));
	linknode *head= (linknode *)malloc(sizeof(linknode));
	linknode *kth= (linknode *)malloc(sizeof(linknode));
	linknode *remove= (linknode *)malloc(sizeof(linknode));
	head = init(h,5);
	//kth = FindKthToTail(head,100);
	
	//AddLinkNode(head,45,0);
	//RemoveLinkNode(head,2);
	//showLinkFromTail(head);
	//remove = head->next;
//	ORemoveLinkNode(remove);
	h = ReverseLink(head);
	while(h->next != NULL)
	{
		printf("%d\n",h->data);
		h = h->next;
	}
	
	printf("\n");
	
	return 0;
}

