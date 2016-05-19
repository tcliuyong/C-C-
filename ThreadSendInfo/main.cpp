#include <pthread.h>
#include <iostream>
#include "thread_tasks.h"
using namespace std;
int answer=10;
int main(int argc,char *argv[])
{
	pthread_t thread1,thread2,thread3;
	cout<<"answer="<<answer<<endl;
	
	pthread_create(&thread1,NULL,task1,NULL);
	pthread_create(&thread2,NULL,task2,NULL);
	pthread_create(&thread3,NULL,task3,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	cout<<"answer="<<answer<<endl;
	return 0;
}
	
