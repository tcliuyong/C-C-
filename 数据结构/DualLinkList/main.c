#include "DualLinkList.h"
int main()
{
	linknode *node = (linknode *)malloc(sizeof(linknode));
	linknode *tnode = (linknode *)malloc(sizeof(linknode));
	node = initDualLinkList(5);
	tnode = removeLinkNode(node,2);
	printf("%d\n",getLinkLen(tnode));
	while(tnode!= NULL)
	{
		printf("%d\n",tnode->data);
		tnode = tnode->next;
	}
	
	return 0;
}
