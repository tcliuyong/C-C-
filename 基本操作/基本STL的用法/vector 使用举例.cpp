#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> vec;
	int a=100;
	vec.push_back(a);//��Ԫ�ص�β�����һ��Ԫ�� 
	cout<<vec[0]<<endl;//Ԫ�ص��±��Ǵ�0��ʼ
	//.insert(vec.begin()+i,a); ��i+1ǰ�����a
	//ɾ��Ԫ�أ�    vec.erase(vec.begin()+2);ɾ����3��Ԫ��  vec.erase(vec.begin()+i,vec.end()+j);ɾ������[i,j-1];�����0��ʼ

 
	vector<int>::iterator it;//ʹ�õ���������vector 
	for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl; 
    cout<<vec.size()<<endl;//��� vec �Ĵ�С
	vec.clear();//������� 
	return 0;
}

 