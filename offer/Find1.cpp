#include<stdio.h>

long long int Count(long long int n){
	//1�ĸ���
	long long int count = 0;
	//��ǰλ
	long long int Factor = 1;
	//��λ����
	long long int LowerNum = 0;
	//��ǰλ����
	long long int CurrNum = 0;
	//��λ����
	long long int HigherNum = 0;
	if(n <= 0){
		return 0;
	}
	while(n / Factor != 0){
		//��λ����
		LowerNum = n - (n / Factor) * Factor;
		//��ǰλ����
		CurrNum = (n / Factor) % 10;
		//��λ����
		HigherNum = n / (Factor * 10);
		//���Ϊ0,����1�Ĵ����ɸ�λ����
		if(CurrNum == 0){
			//���ڸ�λ���� * ��ǰλ��
			count += HigherNum * Factor;
		}
		//���Ϊ1,����1�Ĵ����ɸ�λ�͵�λ����
		else if(CurrNum == 1){
			//��λ���� * ��ǰλ�� + ��λ���� + 1
			count += HigherNum * Factor + LowerNum + 1;
		}
		//�������1,����1�Ĵ����ɸ�λ����
		else{
			//����λ����+1��* ��ǰλ��
			count += (HigherNum + 1) * Factor;
		}
		//ǰ��һλ
		Factor *= 10;
	}
	return count;
}

int main(){
	long long int a;
	while(scanf("%lld",&a) != EOF){
		printf("%lld\n",Count(a));
	}
	return 0;
}
