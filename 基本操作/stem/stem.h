#include <algorithm>
#include <cmath>
using namespace std;
class stem
{
	public :
		int gcd(int , int);
	private:
		int data1;
		int data2;
	
};
int stem::gcd(int data1 ,int data2)
{		
	if (data1 == 0) return data2;
	if (data2 == 0) return data1;
	if (data1 % 2 == 0 && data2 % 2 == 0) return 2 * gcd(data1/2,data2/2);
	else if (data1 % 2 == 0) return gcd(data1/2,data2);
	else if (data2 % 2 == 0) return gcd(data1,data2/2);
	else return gcd(abs(data1-data2),min(data1,data2));
}
