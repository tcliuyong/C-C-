#include <iostream>
#include <ctime>

using namespace std;

#define N 6

int array[N]={1,7,5,3,8,4}; //原始数组
int inverse_count; //逆序对计数

void merge_sort(int low, int high);

void merge_count_inverse(int low, int mid, int high);

void print_array(int n);

int main(int argc, char* *argv)
{
inverse_count = 0;
print_array(N);
merge_sort(0, N - 1);
print_array(N);
cout<<"逆序对数:"<<inverse_count<<endl;
system("pause");
return 0;
}


void merge_sort(int low, int high)
{
	if(low < high)
	{
	   int mid = low + (high - low) / 2; //二分
	
	   //递归分治
	   merge_sort(low, mid);
	   merge_sort(mid + 1, high);
	
	   //二路归并
	   merge_count_inverse(low, mid, high);
	}
}

void merge_count_inverse(int low, int mid, int high)
{
int n = high - low + 1;
int *temp = (int *)malloc(sizeof(int) * n); //存储临时排好序的序列

int i = low, end1 = mid;
int j = mid + 1, end2 = high;
int k = 0;
while(i <= end1 && j <= end2)
{
   //将array[i]和array[j]中小的那个赋给temp[k]
   if(array[i] > array[j])
   {
    temp[k] = array[i++];
    inverse_count += end2 - j + 1;//由于是从大到小排列,如果array[i]>array[j]，那么array[i]大于array[j~end2]
   }
   else
   {
    temp[k] = array[j++];
   }
   k++;
}

//当在上文的循环中某数组没有处理完的时候，把剩下的元素直接赋给temp[k]
while(i <= end1) temp[k++] = array[i++];
while(j <= end2) temp[k++] = array[j++];

//把临时数组中的元素赋给array
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

