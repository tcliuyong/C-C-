#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> vec;
	int a=100;
	vec.push_back(a);//向元素的尾部添加一个元素 
	cout<<vec[0]<<endl;//元素的下标是从0开始
	//.insert(vec.begin()+i,a); 在i+1前面插入a
	//删除元素：    vec.erase(vec.begin()+2);删除第3个元素  vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始

 
	vector<int>::iterator it;//使用迭代器访问vector 
	for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl; 
    cout<<vec.size()<<endl;//输出 vec 的大小
	vec.clear();//清空容器 
	return 0;
}

 