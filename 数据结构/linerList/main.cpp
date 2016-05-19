#include "LinerList.h"
int main()
{
	List ll;
	LinerList linerList;
	//linerList.LinerList();
	for(int i = 1; i < 10; i++)
	{
		linerList.insertList(i,i);
	
	}
	linerList.insertList(3,100);
	if(linerList.findList(1000) != -1)
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}
	linerList.delList(3);
	
	linerList.traverseList();
	//ll =linerList.getLinerListInfo();
	//cout<<ll.MaxSize<<endl;
	return 0;
} 