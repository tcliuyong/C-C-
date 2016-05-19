#include <iostream>
#include "TrieTree.h"
using namespace std;
int main(int argc,char *atrv[])
{
	string str="abc";
	string test="abzsdvsd";
	Trie T;
	T.insert(str);
	if(T.search(test))
	{
		cout<<"find it"<<endl;
	}
	else
	{
		cout<<"I can not find it"<<endl;
	} 
	return 0;
}