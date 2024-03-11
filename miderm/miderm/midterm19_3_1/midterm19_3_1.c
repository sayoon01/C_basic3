#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int solution(int n);
int main(void)
{
	int num;

	scanf("%d", &num);
	printf("%d", solution(num));
}
int solution(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}