#include <iostream>
using namespace std;
double betsy(int);
double pam(int);
void estimate(int line, double (*pf)(int));
int main()
{
	int code;
	cout<<"how many lines of code do you need";
	cin>>code;
	cout<<"Here is Bestry estimate:\n";
	estimate(code, betsy);
	cout<<"Here is Pam estimate\n";
	estimate(code, pam);
	return 0;

}
double betsy(int lns)
{
	return 0.5 * lns;
}
double pam(int lns)
{
	return 0.03 * lns + 0.004 * lns;
}
void estimate(int line, double (*pf)(int))
{
	cout<<line<<"lines will take";
	cout<<(*pf)(line)<<"hours"<<endl;
}