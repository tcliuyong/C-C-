#include <iostream>
#include <fstream>
#include <string>
#define N 100
using namespace std;
struct bianjie
{
     int  min;
     int max;
}bj[N];
struct jiyin
{    char type[15];
	 char chrs[15];
     int  size;
}jy[N];
ifstream ifm1("s.txt", ios::in);
ifstream ifm2("type.txt", ios::in);
ifstream ifm3("chrs.txt", ios::in);
ifstream ifm4("size.txt", ios::in);
int i=0,j=0,k=0;
string line,chrsline,typeline,sizeline;
char aa1[10],aa2[10];

void openfile()
{
	while(!ifm1.eof())
	{
		getline(ifm1, line);
		if(line.empty())
		continue;
	  	sscanf(line.c_str(),"%s %s %*d %*s %*d %d %*s", jy[i].type,jy[i].chrs,&jy[i].size);
	  	i++;
	  	
	}
	while(!ifm2.eof())
	{
		getline(ifm2, typeline);
		if(typeline.empty())
		continue;
	  	sscanf(typeline.c_str(),"%s",aa1);
	 
	}
		while(!ifm3.eof())
	{
		getline(ifm3, chrsline);
		if(chrsline.empty())
		continue;
	  	sscanf(chrsline.c_str(),"%s",aa2);
	}
	while(!ifm4.eof())
	{
		getline(ifm4, sizeline);
		if(sizeline.empty())
		continue;
	  	sscanf(sizeline.c_str(),"%d-%d",&bj[j].min,&bj[j].max);
	  	j++;
	 	//cout<<bj[i-1].min<<"-"<<bj[i-1].max<<endl;
	}
	
	
} 
void closefile()
{
	ifm1.close();
	ifm2.close();
	ifm3.close();
	ifm4.close();
	
}
int main(int argc,char * argv[])
{
	openfile();
	int count[N]={0};
	for(int n=0;n<i;n++)
	{
			
		for(int k=0 ;k<j;k++)
		{
			if(!strcmp(aa1,jy[n].type)&& !strcmp(aa2,jy[n].chrs) &&jy[n].size>bj[k].min&&jy[n].size<bj[k].max)
			{
				count[k]++;
			}
		}
	
	}
	closefile();
		cout<<"类型 色体 范围 计数"<<endl;
	for(int a=0;a<j;a++)

	cout<<aa1<<"  "<<aa2<<" "<<bj[a].min<<"--"<<bj[a].max<<"  "<<count[a]<<endl;
	return 0;
}