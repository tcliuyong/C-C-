#include <iostream>
using namespace std;
int main()
{
	cout<<"DATE:"<<__DATE__<<endl;//系统宏定义
	cout<<"FILE:"<<__FILE__<<endl; //文件信息 
	cout<<"LINE:"<<__LINE__<<endl;//当前代码行 
	cout<<"TIME:"<<__TIME__<<endl;//时间信息 
	return 0;
}