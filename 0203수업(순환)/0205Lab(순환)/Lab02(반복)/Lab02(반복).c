#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n)
{
	int cnt = 1;
	printf("%d ", n);
	while(n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
		cnt++;
		printf("%d ", n);
	}
	return cnt;
}
int main(void)
{
	int num;

	scanf("%d", &num);
	printf("\n길이는 %d\n", get_cycle_number(num));
}