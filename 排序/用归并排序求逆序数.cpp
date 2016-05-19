#include <iostream>
#include <ctime>

using namespace std;

#define N 6

int array[N]={1,7,5,3,8,4}; //ԭʼ����
int inverse_count; //����Լ���

void merge_sort(int low, int high);

void merge_count_inverse(int low, int mid, int high);

void print_array(int n);

int main(int argc, char* *argv)
{
inverse_count = 0;
print_array(N);
merge_sort(0, N - 1);
print_array(N);
cout<<"�������:"<<inverse_count<<endl;
system("pause");
return 0;
}


void merge_sort(int low, int high)
{
	if(low < high)
	{
	   int mid = low + (high - low) / 2; //����
	
	   //�ݹ����
	   merge_sort(low, mid);
	   merge_sort(mid + 1, high);
	
	   //��·�鲢
	   merge_count_inverse(low, mid, high);
	}
}

void merge_count_inverse(int low, int mid, int high)
{
int n = high - low + 1;
int *temp = (int *)malloc(sizeof(int) * n); //�洢��ʱ�ź��������

int i = low, end1 = mid;
int j = mid + 1, end2 = high;
int k = 0;
while(i <= end1 && j <= end2)
{
   //��array[i]��array[j]��С���Ǹ�����temp[k]
   if(array[i] > array[j])
   {
    temp[k] = array[i++];
    inverse_count += end2 - j + 1;//�����ǴӴ�С����,���array[i]>array[j]����ôarray[i]����array[j~end2]
   }
   else
   {
    temp[k] = array[j++];
   }
   k++;
}

//�������ĵ�ѭ����ĳ����û�д������ʱ�򣬰�ʣ�µ�Ԫ��ֱ�Ӹ���temp[k]
while(i <= end1) temp[k++] = array[i++];
while(j <= end2) temp[k++] = array[j++];

//����ʱ�����е�Ԫ�ظ���array
for(int x = 0; x < k; ++x)
   array[low + x] = temp[x];

free(temp);
}

void print_array(int n)
{
for(int i = 0; i < n; ++i)
   cout<<array[i]<<" ";
cout<<endl;
}

