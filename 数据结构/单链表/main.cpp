#include "LinkList.h"
int main(int argc ,char* argv)
{
	Link L;
	L.init();
	for(int i = 1; i <= 5; i++)
	{
		L.addData(i);
	}
	L.showList();
	L.delData(2);
	L.showList();
	L.insertData(9, 2);
	L.showList();
	cout<<L.getData(2)<<endl;
	L.converlist();
	L.showList();
	return 0;
}