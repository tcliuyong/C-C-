#include <iostream>
#include <stdlib.h>
using namespace std;
struct List
{
	int *list;
	int size;
	int MaxSize;
};
class LinerList
{
	private:
	List l;
	public:
	LinerList();
	List getLinerListInfo();
	bool isEmpty();
	void traverseList();
	bool insertList(int pos, int item);
	int findList(int);
	bool delList(int pos);
};

LinerList::LinerList()
{
	l.MaxSize = 100;
	l.list = new int[l.MaxSize];
	if(l.list == NULL)
	{
		cout<<"空间使用完毕"<<endl;
		exit(1); 
	}
	l.size = 0;
}
List LinerList::getLinerListInfo()
{	
	return l;
}
bool LinerList::isEmpty()
{
	return l.size == 0;
}
void LinerList::traverseList()
{
	for(int i = 0 ; i < l.size; i++)
	{
		cout<<l.list[i]<<endl;
	}
}
int LinerList::findList(int item)
{
	for(int i = 0; i<l.size; i++)
	{
		if(l.list[i] == item)
		{
			return i;
		}
		else
		{
			
			return -1;
		}	
	}
	return -1;
}
bool LinerList::insertList(int pos, int item)
{
	if(pos < -1 || pos > l.size + 1)
	{
		return false;
	}
	int i ;
	if(l.size == l.MaxSize)
	{
		int k = sizeof(item);
		l.list = (int *) realloc(l.list,2 * l.MaxSize * k);
		if(l.list == NULL)
		{
			cout<<"空间不足"<<endl;
			exit(1);
		}	
		l.MaxSize = 2 * l.MaxSize;
	}
	for(i = l.size - 1; i >= pos-1; i--)
	{
		l.list[i + 1] = l.list[i];
	}
	l.list[pos - 1] = item;
	l.size++;
	return true;
}
bool LinerList::delList(int pos)
{
	if(l.size == 0)
	{
		cout<<"线性表中没有数据"<<endl;
		return false;
	}
	if(pos < -1 || pos > l.size + 1)
	{
		cout<<"输入的位置有误"<<endl;
		return false;
	}
	for(int i = pos; i < l.size; i++)
	{
		l.list[i-1] = l.list[i];
	}	
	l.size--;
	
	return true;
}