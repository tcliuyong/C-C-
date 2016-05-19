#include <stdio.h>
#include  <stdlib.h>
#include <iostream>
using namespace std;
typedef struct treenode
{
	int data;
	struct treenode *left;
	struct treenode *right;
} treenode;

treenode *insertBinTree(treenode *root,int data)
{
		treenode *newnode = (treenode *)malloc(sizeof(treenode));
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->data = data;
	if(!root)
			{
			 root=newnode;
			// root->left=root->right=NULL;
			}
		else if (data < root->data)
			root->left=insertBinTree(root->left,data);
		else
			root->right=insertBinTree(root->right,data);
		return root;
}
void show(treenode *root)
{
	if(root==NULL)
	{
		return ;
	} 
	show(root->left);
	printf("%d ",root->data);
	show(root->right);	
}
bool DeleteNode(treenode *root,int x)
{
	bool find=false;
	treenode *q;
	q= (treenode *)malloc(sizeof(treenode));
	while(!find && root)
	{
		if(x==root->data)
		{
			find=true;
		}
		else if(x>root->data)
		{
			q=root;
			root=root->right;	
		}	
		else if(x<root->data)
		{
			q=root;
			root=root->left;	
		}
	} 
	if(root==NULL)
	{
		cout<<"can not find it"<<endl;
	}
	if(root->left==NULL&&root->right==NULL)
	{	
		cout<<"successful"<<endl;
		free (root);
		return true;	
	}
	else if(root->left==NULL||root->right==NULL)
	{
		if(root->left==NULL)
		{
			if(q->data > root->data)
			{
				q->left=root->right; 
				free(root);	
				return true;	
			}
			else
			{
				q->right=root->right;			
				free(root);
				return true;
			}
			
		}
		else if(root->right==NULL)
		{
			if(q->data > root->data)
			{
				q->left=root->left;		
				free(root);
				return true;
			}
			else
			{
				q->right=root->left;			
				free(root);
				return true;
			}
		}
	}
	else
	{
		if(q->left == root && root->left)
			{ //p是q的左子树且p有左子树 
                q->left = root->right;    //将p的左子树链接到q的左指针上 
                free(root);
            }    
            else if(q->left == root && root->right)
			{
                q->left = root->right;   
				free(root); 
            }
            else if(q->right == root && root->left)
			{
                q->right = root->left; 
				free(root);   
            }
            else
			{
                q->right = root->right;
                free(root);
            }
        }
        return false;
}
int  main()
{
	treenode *root = (treenode *)malloc(sizeof(treenode));
	root = NULL;
	int i;
	int a[]={3,1,4,2,5,7,0};
	for(i = 0; i < 7; i++)
	root = insertBinTree(root,a[i]);
	show(root);
	DeleteNode(root,5);
	show(root);
	return 0;
}
