#include <iostream>
#include <cmath>
using namespace std;
typedef struct  L
{
    int key;
    struct L *prior, *next;
}Type;
void append(Type *L,Type *L1)
{
	if (L1->next!=L1)
	{
		L->prior->next=L1->next;
		L1->next->prior=L->prior;
		L1->prior->next=L;
		L->prior=L1->prior;
	}
}
int get_digital(Type *p,int i)
{
	int key;
	key=p->key;
	if(i!=0)
		key=key/pow(10,i*1.0);
	return key%10;
}
void add_entry(Type *L,Type *p)
{
	p->prior=L->prior;
	p->next=L;
	L->prior->next=p;
	L->prior=p;
}
Type *del_entry(Type *L)
{
	Type *p;
	p=L->next;
	if(p!=L)
	{
		p->prior->next=p->next;
		p->next->prior=p->prior;
	}
	else{
		p=NULL;
	}
	return p;
}
void radix_sort(Type *L,int k)
{
	Type *Lhead[10],*p;
	int i,j;
	for (i=0;i<10;i++)
        Lhead[i] = new Type;
	for (i=0;i<k;i++)
	{
		for (j=0;j<10;j++)
			Lhead[j]->prior=Lhead[j]->next=Lhead[j];
		while (L->next!=L)
		{
			p=del_entry(L);
			j=get_digital(p,i);
			add_entry(Lhead[j],p);
		}
		for (j=0;j<10;j++)
			append(L,Lhead[j]);
	}
	for (i=0;i<10;i++)
	{
		delete(Lhead[i]);
	}
}
int main()
{
	Type *A = (Type *)malloc(sizeof(A));
	Type *rem = A;
	A->key = 0;
	A->prior = NULL;
	A->next = NULL;
	int w = 10;
	while(w--)
	{
        Type *temp = (Type *)malloc(sizeof(temp));
	    cin>>temp->key;
	    temp->prior = A;
	    temp->next = NULL;
	    A->next = temp;
	    A=A->next;
	}
	A->next = rem;
	rem->prior = A;
	A=A->next;
	cout<<"before:"<<endl;
	A=A->next;
	while(A != rem)
	{
		cout<<A->key<<" ";
		A=A->next;
	}
	A=rem;
	radix_sort(A,4);
	cout<<endl<<"after:"<<endl;
	A=rem;
	A=A->next;
	while(A != rem)
	{
	    cout<<A->key<<" ";
		A=A->next;
	}
	cout<<endl;
	return 0;
}

	/*
	{3097,3673,2985,1358,6138,9135,4782,1367,3684,0139};
	*/
