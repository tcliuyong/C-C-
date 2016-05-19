extern int answer;
void *task1(void *X)
{
	answer =answer*32;
}
void *task2(void *X)
{
		answer =answer/2;
}
void *task3(void *X)
{
		answer =answer+5;
}
