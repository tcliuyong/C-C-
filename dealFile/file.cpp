#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(int argc,char* argv[])
{
	ofstream fo("wr1.dat");
	if(!fo)
	{
		cerr<<"wr1.dat not a file";
		exit(1);
	}
	for(int i = 0; i < 20; i++)
	{
		fo<<i<<" ";
	}
	fo.close();
	ifstream fi("wr1.dat",ios::in);
	if(!fi)
	{
		cerr<<"not found";
		exit(1);
	}
	int i ;
	while(!fi.eof())
	{
		if(fi>>i)
		cout<<i<<endl;
	}
	cout<<endl;
	fi.close();
	return 0;
	
}