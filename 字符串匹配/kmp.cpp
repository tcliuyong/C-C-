#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
void kmp_match(char *text, char *p, int *next)
{
	int 	m, n, s, q;

	m = strlen(p);
	n = strlen(text);
	q = s = 0;	/* q��ʾ��һ�ε���ƥ���˶��ٸ��ַ���
				   s��ʾ��ε�����text���ĸ��ַ���ʼ�Ƚ� */ 
	while (s < n) {
		for (q = next[q]; q < m && p[q] == text[s]; q++, s++);
		if (q == 0) s++;
		else if (q == m) {
			printf("pattern occurs with shift %d-%d\n", s-m,s);
		}
	}
}
void compute_prefix(int *next, char *p)
{
	int		i, n, k;
	n = strlen(p);
	next[1] = next[0] = 0;
	k = 0;		/* ��i�ε�����ʼ֮ǰ��k��ʾnext[i-1]��ֵ */	
	for (i = 2; i <= n; i++) {
		for (; k != 0 && p[k] != p[i-1]; k = next[k]);
		if (p[k] == p[i-1]) k++;
		next[i] = k;
	}
}
int main()
{
	int 	next[101], n;
	char	*p = "bcbab";
	char	*text = "bacbababaabcbab";

	compute_prefix(next, p);
	kmp_match(text, p, next);

	return 0;
}